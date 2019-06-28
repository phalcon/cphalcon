[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Exception",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 13,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 15,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DispatcherInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 16,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 17,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 18,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Exception",
                "alias": "PhalconException",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 19,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\FilterInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 20,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Binder",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 21,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\BinderInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 22,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 28,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is the base class for Phalcon\\Mvc\\Dispatcher and Phalcon\\Cli\\Dispatcher.\n * This class can't be instantiated directly, you can use it to create your own\n * dispatchers.\n *",
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 29,
        "char": 8
    },
    {
        "type": "class",
        "name": "Dispatcher",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "DispatcherInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 29,
                "char": 57
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 29,
                "char": 82
            },
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Dispatcher.zep",
                "line": 30,
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
                    "name": "activeHandler",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 42,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeMethodMap",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 43,
                        "char": 35
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 45,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "actionName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 45,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 49,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "actionSuffix",
                    "default": {
                        "type": "string",
                        "value": "Action",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 50,
                        "char": 36
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 54,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "camelCaseMap",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 55,
                        "char": 32
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 57,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 61,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultAction",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 62,
                        "char": 31
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 64,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultNamespace",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 64,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 66,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultHandler",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 66,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 70,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handlerHashes",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 71,
                        "char": 33
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 73,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handlerName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 73,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 77,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handlerSuffix",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 78,
                        "char": 31
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 80,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 84,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "finished",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 85,
                        "char": 31
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 89,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "forwarded",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 90,
                        "char": 32
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 94,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "isControllerInitialize",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 95,
                        "char": 45
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 96,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "lastHandler",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 96,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 97,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "modelBinder",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 97,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 101,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "modelBinding",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 102,
                        "char": 35
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 103,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "moduleName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 103,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 104,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "namespaceName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 104,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 108,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "params",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 109,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 110,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "previousActionName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 110,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 111,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "previousHandlerName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 111,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 112,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "previousNamespaceName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 112,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 113,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "returnedValue",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 113,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 115,
                    "char": 10
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "callActionMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 115,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "actionMethod",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 115,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 115,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 115,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "call_user_func_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "handler",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 118,
                                                        "char": 21
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 118,
                                                    "char": 21
                                                },
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "actionMethod",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 118,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 118,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 118,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 118,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 120,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 120,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 120,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 121,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 115,
                    "last-line": 132,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dispatch",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "hasService",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 135,
                                    "char": 24
                                },
                                {
                                    "variable": "hasEventsManager",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 135,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 136,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "numberDispatches",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 136,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 137,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 137,
                                    "char": 18
                                },
                                {
                                    "variable": "handler",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 137,
                                    "char": 27
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 137,
                                    "char": 38
                                },
                                {
                                    "variable": "namespaceName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 137,
                                    "char": 53
                                },
                                {
                                    "variable": "handlerName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 137,
                                    "char": 66
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 137,
                                    "char": 78
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 138,
                                    "char": 19
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 138,
                                    "char": 34
                                },
                                {
                                    "variable": "handlerClass",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 138,
                                    "char": 48
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 138,
                                    "char": 56
                                },
                                {
                                    "variable": "actionMethod",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 138,
                                    "char": 70
                                },
                                {
                                    "variable": "modelBinder",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 139,
                                    "char": 24
                                },
                                {
                                    "variable": "bindCacheKey",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 139,
                                    "char": 38
                                },
                                {
                                    "variable": "isNewHandler",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 139,
                                    "char": 52
                                },
                                {
                                    "variable": "handlerHash",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 139,
                                    "char": 65
                                },
                                {
                                    "variable": "e",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 139,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 141,
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
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "DiInterface",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 141,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 141,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 141,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 141,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 141,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 141,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 143,
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 143,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 143,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 143,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 143,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 144,
                                            "char": 18
                                        },
                                        "name": "throwDispatchException",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "PhalconException",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "related dispatching services",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 147,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 147,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 147,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 147,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 149,
                                                        "char": 13
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EXCEPTION_NO_DI",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 149,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 149,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 149,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 149,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 151,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 151,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 152,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 154,
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
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "ManagerInterface",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 154,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 154,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 154,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 154,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 154,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 154,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 155,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hasEventsManager",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 155,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 155,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 155,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 155,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 155,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 156,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "finished",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 156,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 156,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 158,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "hasEventsManager",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 158,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "try-catch",
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "eventsManager",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 162,
                                                            "char": 34
                                                        },
                                                        "name": "fire",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "dispatch:beforeDispatchLoop",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 162,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 162,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 162,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 162,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 162,
                                                        "char": 77
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 162,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 162,
                                                    "char": 86
                                                },
                                                "right": {
                                                    "type": "not-identical",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 162,
                                                            "char": 93
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "finished",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 162,
                                                            "char": 105
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 162,
                                                        "char": 105
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 162,
                                                        "char": 113
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 162,
                                                    "char": 113
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 162,
                                                "char": 113
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 163,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 164,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 165,
                                            "char": 13
                                        }
                                    ],
                                    "catches": [
                                        {
                                            "classes": [
                                                {
                                                    "type": "variable",
                                                    "value": "Exception",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 165,
                                                    "char": 30
                                                }
                                            ],
                                            "variable": {
                                                "type": "variable",
                                                "value": "e",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 196,
                                                "char": 9
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
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 182,
                                                                    "char": 35
                                                                },
                                                                "name": "handleException",
                                                                "call-type": 3,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "e",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 182,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 182,
                                                                        "char": 55
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 182,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 182,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 184,
                                                    "char": 18
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not-identical",
                                                        "left": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 184,
                                                                "char": 25
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "finished",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 184,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 184,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 184,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 184,
                                                        "char": 45
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "identical",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "status",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 186,
                                                                    "char": 33
                                                                },
                                                                "right": {
                                                                    "type": "bool",
                                                                    "value": "false",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 186,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 186,
                                                                "char": 41
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "return",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 187,
                                                                        "char": 37
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 188,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 191,
                                                            "char": 25
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 191,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 192,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 195,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 196,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 196,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 198,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 198,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handler",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 199,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 199,
                                    "char": 27
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "numberDispatches",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 200,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 200,
                                    "char": 33
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "finished",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 202,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 202,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 204,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 204,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "finished",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 204,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 204,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 204,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "incr",
                                            "variable": "numberDispatches",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 205,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 208,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "numberDispatches",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 208,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "256",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 208,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 208,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 208,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 209,
                                                    "char": 22
                                                },
                                                "name": "throwDispatchException",
                                                "call-type": 3,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "Dispatcher has detected a cyclic routing causing stability problems",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 210,
                                                            "char": 88
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 210,
                                                        "char": 88
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "self",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 212,
                                                                "char": 17
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "EXCEPTION_CYCLIC_ROUTING",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 212,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 212,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 212,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 212,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 214,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 215,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 217,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "finished",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 217,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 217,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 219,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 219,
                                            "char": 18
                                        },
                                        "name": "resolveEmptyProperties",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 219,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 221,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hasEventsManager",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 221,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "try-catch",
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "eventsManager",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 224,
                                                                    "char": 38
                                                                },
                                                                "name": "fire",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "dispatch:beforeDispatch",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 224,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 224,
                                                                        "char": 67
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 224,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 224,
                                                                        "char": 73
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 224,
                                                                "char": 77
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 224,
                                                                "char": 86
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 224,
                                                            "char": 86
                                                        },
                                                        "right": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 224,
                                                                    "char": 93
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "finished",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 224,
                                                                    "char": 105
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 224,
                                                                "char": 105
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 224,
                                                                "char": 113
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 224,
                                                            "char": 113
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 224,
                                                        "char": 113
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 226,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 227,
                                                    "char": 17
                                                }
                                            ],
                                            "catches": [
                                                {
                                                    "classes": [
                                                        {
                                                            "type": "variable",
                                                            "value": "Exception",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 227,
                                                            "char": 34
                                                        }
                                                    ],
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 234,
                                                        "char": 13
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 228,
                                                                            "char": 29
                                                                        },
                                                                        "name": "handleException",
                                                                        "call-type": 3,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "e",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 228,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 228,
                                                                                "char": 49
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 228,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 228,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 228,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 228,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "finished",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 228,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 228,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 228,
                                                                        "char": 89
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 228,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 228,
                                                                "char": 89
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 230,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 232,
                                                            "char": 25
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 232,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 233,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 234,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 234,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 236,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handlerClass",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 236,
                                                    "char": 37
                                                },
                                                "name": "getHandlerClass",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 236,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 236,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 242,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hasService",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 242,
                                                        "char": 47
                                                    },
                                                    "name": "has",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "handlerClass",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 242,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 242,
                                                            "char": 64
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 242,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 242,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 242,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 244,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "hasService",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 244,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 244,
                                        "char": 28
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "hasService",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "bool",
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "class_exists",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "handlerClass",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 249,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 249,
                                                                    "char": 66
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 249,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 249,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 249,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 250,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 253,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "hasService",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 253,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 253,
                                        "char": 28
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
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 254,
                                                            "char": 35
                                                        },
                                                        "name": "throwDispatchException",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "handlerClass",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 255,
                                                                        "char": 34
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": " handler class cannot be loaded",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 255,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 255,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 255,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "self",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 257,
                                                                        "char": 17
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "EXCEPTION_HANDLER_NOT_FOUND",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 257,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 257,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 257,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 257,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 257,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 259,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "status",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 259,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 259,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 259,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 259,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "finished",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 259,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 259,
                                                        "char": 57
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 259,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 259,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 259,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 261,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 263,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 264,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 266,
                                    "char": 15
                                },
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
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 266,
                                                    "char": 37
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "handlerClass",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 266,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 266,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 266,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 266,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 269,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 269,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 269,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 269,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 269,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 269,
                                        "char": 51
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
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 270,
                                                            "char": 35
                                                        },
                                                        "name": "throwDispatchException",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "Invalid handler returned from the services container",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 271,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 271,
                                                                "char": 73
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "self",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 273,
                                                                        "char": 17
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "EXCEPTION_INVALID_HANDLER",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 273,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 273,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 273,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 273,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 273,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 275,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "status",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 275,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 275,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 275,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 275,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "finished",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 275,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 275,
                                                        "char": 57
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 275,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 275,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 275,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 277,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 279,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 280,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 283,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handlerHash",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "spl_object_hash",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 283,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 283,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 283,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 283,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 285,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "isNewHandler",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 285,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "handlerHashes",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 285,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 285,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "handlerHash",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 285,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 285,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 285,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 285,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 285,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 285,
                                            "char": 73
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 287,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "isNewHandler",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 287,
                                        "char": 29
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "handlerHashes",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "handlerHash",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 288,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 288,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 288,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 289,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 291,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeHandler",
                                            "expr": {
                                                "type": "variable",
                                                "value": "handler",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 291,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 291,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 293,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "namespaceName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 293,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "namespaceName",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 293,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 293,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 293,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 294,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handlerName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 294,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "handlerName",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 294,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 294,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 294,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 295,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "actionName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 295,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 295,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 295,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 295,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 296,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 296,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 296,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 296,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 296,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 301,
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
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 301,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 301,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 301,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 301,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 301,
                                        "char": 48
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
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 305,
                                                            "char": 35
                                                        },
                                                        "name": "throwDispatchException",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "Action parameters must be an Array",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 306,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 306,
                                                                "char": 55
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "self",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 308,
                                                                        "char": 17
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "EXCEPTION_INVALID_PARAMS",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 308,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 308,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 308,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 308,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 308,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 310,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "status",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 310,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 310,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 310,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 310,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "finished",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 310,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 310,
                                                        "char": 57
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 310,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 310,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 310,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 312,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 314,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 315,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 318,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "actionMethod",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 318,
                                                    "char": 37
                                                },
                                                "name": "getActiveMethod",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 318,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 318,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 320,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "fcall",
                                                "name": "is_callable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "handler",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 320,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 320,
                                                                    "char": 46
                                                                },
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "actionMethod",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 320,
                                                                        "char": 60
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 320,
                                                                    "char": 60
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 320,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 320,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 320,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 320,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 320,
                                        "char": 63
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "hasEventsManager",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 321,
                                                "char": 37
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "eventsManager",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 322,
                                                                "char": 38
                                                            },
                                                            "name": "fire",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "dispatch:beforeNotFoundAction",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 322,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 322,
                                                                    "char": 73
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 322,
                                                                        "char": 79
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 322,
                                                                    "char": 79
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 322,
                                                            "char": 83
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 322,
                                                            "char": 91
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 322,
                                                        "char": 91
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 324,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 326,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 326,
                                                                "char": 29
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "finished",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 326,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 326,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 326,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 326,
                                                        "char": 49
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 328,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 329,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 335,
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
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 335,
                                                            "char": 35
                                                        },
                                                        "name": "throwDispatchException",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "string",
                                                                                    "value": "Action '",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 336,
                                                                                    "char": 30
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "actionName",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 336,
                                                                                    "char": 43
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 336,
                                                                                "char": 43
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' was not found on handler '",
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 336,
                                                                                "char": 74
                                                                            },
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 336,
                                                                            "char": 74
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "handlerName",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 336,
                                                                            "char": 88
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 336,
                                                                        "char": 88
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "'",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 336,
                                                                        "char": 91
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 336,
                                                                    "char": 91
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 336,
                                                                "char": 91
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "self",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 338,
                                                                        "char": 17
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "EXCEPTION_ACTION_NOT_FOUND",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 338,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 338,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 338,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 338,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 338,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 340,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "status",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 340,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 340,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 340,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 340,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "finished",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 340,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 340,
                                                        "char": 57
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 340,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 340,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 340,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 342,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 344,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 345,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 359,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hasEventsManager",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 359,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "try-catch",
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "eventsManager",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 362,
                                                                    "char": 38
                                                                },
                                                                "name": "fire",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "dispatch:beforeExecuteRoute",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 362,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 362,
                                                                        "char": 71
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 362,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 362,
                                                                        "char": 77
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 362,
                                                                "char": 81
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 362,
                                                                "char": 90
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 362,
                                                            "char": 90
                                                        },
                                                        "right": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 362,
                                                                    "char": 97
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "finished",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 362,
                                                                    "char": 109
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 362,
                                                                "char": 109
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 362,
                                                                "char": 117
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 362,
                                                            "char": 117
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 362,
                                                        "char": 117
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "container",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 363,
                                                                    "char": 35
                                                                },
                                                                "name": "remove",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "handlerClass",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 363,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 363,
                                                                        "char": 55
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 363,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 364,
                                                            "char": 32
                                                        },
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 365,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 366,
                                                    "char": 17
                                                }
                                            ],
                                            "catches": [
                                                {
                                                    "classes": [
                                                        {
                                                            "type": "variable",
                                                            "value": "Exception",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 366,
                                                            "char": 34
                                                        }
                                                    ],
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 375,
                                                        "char": 13
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 367,
                                                                            "char": 29
                                                                        },
                                                                        "name": "handleException",
                                                                        "call-type": 3,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "e",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 367,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 367,
                                                                                "char": 49
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 367,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 367,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 367,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 367,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "finished",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 367,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 367,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 367,
                                                                        "char": 89
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 367,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 367,
                                                                "char": 89
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "mcall",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "container",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 368,
                                                                            "char": 35
                                                                        },
                                                                        "name": "remove",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "handlerClass",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 368,
                                                                                    "char": 55
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 368,
                                                                                "char": 55
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 368,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 370,
                                                                    "char": 32
                                                                },
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 371,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 373,
                                                            "char": 25
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 373,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 374,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 375,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 375,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 377,
                                    "char": 14
                                },
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
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 377,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 377,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "beforeExecuteRoute",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 377,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 377,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 377,
                                        "char": 59
                                    },
                                    "statements": [
                                        {
                                            "type": "try-catch",
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 380,
                                                                    "char": 32
                                                                },
                                                                "name": "beforeExecuteRoute",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 380,
                                                                            "char": 56
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 380,
                                                                        "char": 56
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 380,
                                                                "char": 60
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 380,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 380,
                                                            "char": 69
                                                        },
                                                        "right": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 380,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "finished",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 380,
                                                                    "char": 88
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 380,
                                                                "char": 88
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 380,
                                                                "char": 96
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 380,
                                                            "char": 96
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 380,
                                                        "char": 96
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "container",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 381,
                                                                    "char": 35
                                                                },
                                                                "name": "remove",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "handlerClass",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 381,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 381,
                                                                        "char": 55
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 381,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 383,
                                                            "char": 32
                                                        },
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 384,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 385,
                                                    "char": 17
                                                }
                                            ],
                                            "catches": [
                                                {
                                                    "classes": [
                                                        {
                                                            "type": "variable",
                                                            "value": "Exception",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 385,
                                                            "char": 34
                                                        }
                                                    ],
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 394,
                                                        "char": 13
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 386,
                                                                            "char": 29
                                                                        },
                                                                        "name": "handleException",
                                                                        "call-type": 3,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "e",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 386,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 386,
                                                                                "char": 49
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 386,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 386,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 386,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 386,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "finished",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 386,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 386,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 386,
                                                                        "char": 89
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 386,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 386,
                                                                "char": 89
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "mcall",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "container",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 387,
                                                                            "char": 35
                                                                        },
                                                                        "name": "remove",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "handlerClass",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 387,
                                                                                    "char": 55
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 387,
                                                                                "char": 55
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 387,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 389,
                                                                    "char": 32
                                                                },
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 390,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 392,
                                                            "char": 25
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 392,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 393,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 394,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 394,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 413,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "isNewHandler",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 413,
                                        "char": 29
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
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 414,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 414,
                                                        "char": 41
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "initialize",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 414,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 414,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 414,
                                                "char": 55
                                            },
                                            "statements": [
                                                {
                                                    "type": "try-catch",
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "isControllerInitialize",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 416,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 416,
                                                                    "char": 64
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 418,
                                                            "char": 31
                                                        },
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 418,
                                                                    "char": 33
                                                                },
                                                                "name": "initialize",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 418,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 419,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "catches": [
                                                        {
                                                            "classes": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "Exception",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 419,
                                                                    "char": 38
                                                                }
                                                            ],
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 436,
                                                                "char": 17
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "object-property",
                                                                            "operator": "assign",
                                                                            "variable": "this",
                                                                            "property": "isControllerInitialize",
                                                                            "expr": {
                                                                                "type": "bool",
                                                                                "value": "false",
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 420,
                                                                                "char": 65
                                                                            },
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 420,
                                                                            "char": 65
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 430,
                                                                    "char": 26
                                                                },
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "or",
                                                                        "left": {
                                                                            "type": "identical",
                                                                            "left": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 430,
                                                                                    "char": 33
                                                                                },
                                                                                "name": "handleException",
                                                                                "call-type": 3,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "e",
                                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                            "line": 430,
                                                                                            "char": 53
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                        "line": 430,
                                                                                        "char": 53
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 430,
                                                                                "char": 57
                                                                            },
                                                                            "right": {
                                                                                "type": "bool",
                                                                                "value": "false",
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 430,
                                                                                "char": 66
                                                                            },
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 430,
                                                                            "char": 66
                                                                        },
                                                                        "right": {
                                                                            "type": "identical",
                                                                            "left": {
                                                                                "type": "property-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 430,
                                                                                    "char": 73
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "finished",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 430,
                                                                                    "char": 85
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 430,
                                                                                "char": 85
                                                                            },
                                                                            "right": {
                                                                                "type": "bool",
                                                                                "value": "false",
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 430,
                                                                                "char": 93
                                                                            },
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 430,
                                                                            "char": 93
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 430,
                                                                        "char": 93
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "continue",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 432,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 434,
                                                                    "char": 29
                                                                },
                                                                {
                                                                    "type": "throw",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "e",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 434,
                                                                        "char": 32
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 435,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 436,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 436,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 438,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "isControllerInitialize",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 438,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 438,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 443,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 443,
                                                "char": 34
                                            },
                                            "statements": [
                                                {
                                                    "type": "try-catch",
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "eventsManager",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 445,
                                                                            "char": 42
                                                                        },
                                                                        "name": "fire",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "dispatch:afterInitialize",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 445,
                                                                                    "char": 72
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 445,
                                                                                "char": 72
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 445,
                                                                                    "char": 78
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 445,
                                                                                "char": 78
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 445,
                                                                        "char": 82
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 445,
                                                                        "char": 91
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 445,
                                                                    "char": 91
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 445,
                                                                            "char": 98
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "finished",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 445,
                                                                            "char": 110
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 445,
                                                                        "char": 110
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 445,
                                                                        "char": 118
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 445,
                                                                    "char": 118
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 445,
                                                                "char": 118
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 447,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 448,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "catches": [
                                                        {
                                                            "classes": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "Exception",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 448,
                                                                    "char": 38
                                                                }
                                                            ],
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 455,
                                                                "char": 17
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "or",
                                                                        "left": {
                                                                            "type": "identical",
                                                                            "left": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 449,
                                                                                    "char": 33
                                                                                },
                                                                                "name": "handleException",
                                                                                "call-type": 3,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "e",
                                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                            "line": 449,
                                                                                            "char": 53
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                        "line": 449,
                                                                                        "char": 53
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 449,
                                                                                "char": 57
                                                                            },
                                                                            "right": {
                                                                                "type": "bool",
                                                                                "value": "false",
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 449,
                                                                                "char": 66
                                                                            },
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 449,
                                                                            "char": 66
                                                                        },
                                                                        "right": {
                                                                            "type": "identical",
                                                                            "left": {
                                                                                "type": "property-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 449,
                                                                                    "char": 73
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "finished",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 449,
                                                                                    "char": 85
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 449,
                                                                                "char": 85
                                                                            },
                                                                            "right": {
                                                                                "type": "bool",
                                                                                "value": "false",
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 449,
                                                                                "char": 93
                                                                            },
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 449,
                                                                            "char": 93
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 449,
                                                                        "char": 93
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "continue",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 451,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 453,
                                                                    "char": 29
                                                                },
                                                                {
                                                                    "type": "throw",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "e",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 453,
                                                                        "char": 32
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 454,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 455,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 455,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 456,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 458,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 458,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "modelBinding",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 458,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 458,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "modelBinder",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 459,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "modelBinder",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 459,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 459,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 459,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 460,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "bindCacheKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "_PHMB_",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 460,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "handlerClass",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 460,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 460,
                                                                "char": 58
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "_",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 460,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 460,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "actionMethod",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 460,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 460,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 460,
                                                    "char": 76
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 462,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "modelBinder",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 462,
                                                            "char": 42
                                                        },
                                                        "name": "bindToHandler",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 463,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 463,
                                                                "char": 28
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "params",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 464,
                                                                    "char": 27
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 464,
                                                                "char": 27
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindCacheKey",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 465,
                                                                    "char": 33
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 465,
                                                                "char": 33
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "actionMethod",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 467,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 467,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 467,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 467,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 468,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 473,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hasEventsManager",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 473,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "eventsManager",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 474,
                                                        "char": 34
                                                    },
                                                    "name": "fire",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "dispatch:afterBinding",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 474,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 474,
                                                            "char": 61
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 474,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 474,
                                                            "char": 67
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 474,
                                                    "char": 71
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 474,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 474,
                                                "char": 79
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 476,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 481,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 481,
                                                        "char": 25
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "finished",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 481,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 481,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 481,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 481,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 483,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 484,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 489,
                                    "char": 14
                                },
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
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 489,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 489,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "afterBinding",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 489,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 489,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 489,
                                        "char": 53
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "handler",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 490,
                                                        "char": 28
                                                    },
                                                    "name": "afterBinding",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 490,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 490,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 490,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 490,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 490,
                                                "char": 58
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 492,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 497,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 497,
                                                        "char": 25
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "finished",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 497,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 497,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 497,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 497,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 499,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 500,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 505,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "lastHandler",
                                            "expr": {
                                                "type": "variable",
                                                "value": "handler",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 505,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 505,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 507,
                                    "char": 15
                                },
                                {
                                    "type": "try-catch",
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "returnedValue",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 511,
                                                            "char": 48
                                                        },
                                                        "name": "callActionMethod",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 512,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 512,
                                                                "char": 28
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "actionMethod",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 513,
                                                                    "char": 33
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 513,
                                                                "char": 33
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "params",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 515,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 515,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 515,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 515,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 517,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 517,
                                                        "char": 25
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "finished",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 517,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 517,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 517,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 517,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 519,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 520,
                                            "char": 13
                                        }
                                    ],
                                    "catches": [
                                        {
                                            "classes": [
                                                {
                                                    "type": "variable",
                                                    "value": "Exception",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 520,
                                                    "char": 30
                                                }
                                            ],
                                            "variable": {
                                                "type": "variable",
                                                "value": "e",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 531,
                                                "char": 14
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 521,
                                                                    "char": 25
                                                                },
                                                                "name": "handleException",
                                                                "call-type": 3,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "e",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 521,
                                                                            "char": 45
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 521,
                                                                        "char": 45
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 521,
                                                                "char": 49
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 521,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 521,
                                                            "char": 58
                                                        },
                                                        "right": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 521,
                                                                    "char": 65
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "finished",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 521,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 521,
                                                                "char": 77
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 521,
                                                                "char": 85
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 521,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 521,
                                                        "char": 85
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 523,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 525,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "throw",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 525,
                                                        "char": 24
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 526,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 531,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 531,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hasEventsManager",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 531,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "try-catch",
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "eventsManager",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 533,
                                                                    "char": 38
                                                                },
                                                                "name": "fire",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "dispatch:afterExecuteRoute",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 533,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 533,
                                                                        "char": 70
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 533,
                                                                            "char": 76
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 533,
                                                                        "char": 76
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 533,
                                                                            "char": 83
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 533,
                                                                        "char": 83
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 533,
                                                                "char": 87
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 533,
                                                                "char": 96
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 533,
                                                            "char": 96
                                                        },
                                                        "right": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 533,
                                                                    "char": 103
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "finished",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 533,
                                                                    "char": 115
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 533,
                                                                "char": 115
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 533,
                                                                "char": 123
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 533,
                                                            "char": 123
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 533,
                                                        "char": 123
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 535,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 536,
                                                    "char": 17
                                                }
                                            ],
                                            "catches": [
                                                {
                                                    "classes": [
                                                        {
                                                            "type": "variable",
                                                            "value": "Exception",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 536,
                                                            "char": 34
                                                        }
                                                    ],
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 543,
                                                        "char": 13
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 537,
                                                                            "char": 29
                                                                        },
                                                                        "name": "handleException",
                                                                        "call-type": 3,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "e",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 537,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 537,
                                                                                "char": 49
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 537,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 537,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 537,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 537,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "finished",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 537,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 537,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 537,
                                                                        "char": 89
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 537,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 537,
                                                                "char": 89
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 539,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 541,
                                                            "char": 25
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 541,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 542,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 543,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 543,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 548,
                                    "char": 14
                                },
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
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 548,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 548,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "afterExecuteRoute",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 548,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 548,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 548,
                                        "char": 58
                                    },
                                    "statements": [
                                        {
                                            "type": "try-catch",
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 550,
                                                                    "char": 32
                                                                },
                                                                "name": "afterExecuteRoute",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 550,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 550,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 550,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 550,
                                                                        "char": 62
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 550,
                                                                "char": 66
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 550,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 550,
                                                            "char": 75
                                                        },
                                                        "right": {
                                                            "type": "identical",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 550,
                                                                    "char": 82
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "finished",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 550,
                                                                    "char": 94
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 550,
                                                                "char": 94
                                                            },
                                                            "right": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 550,
                                                                "char": 102
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 550,
                                                            "char": 102
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 550,
                                                        "char": 102
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 552,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 553,
                                                    "char": 17
                                                }
                                            ],
                                            "catches": [
                                                {
                                                    "classes": [
                                                        {
                                                            "type": "variable",
                                                            "value": "Exception",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 553,
                                                            "char": 34
                                                        }
                                                    ],
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 560,
                                                        "char": 13
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 554,
                                                                            "char": 29
                                                                        },
                                                                        "name": "handleException",
                                                                        "call-type": 3,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "e",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 554,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 554,
                                                                                "char": 49
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 554,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 554,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 554,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 554,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "finished",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 554,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 554,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 554,
                                                                        "char": 89
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 554,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 554,
                                                                "char": 89
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 556,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 558,
                                                            "char": 25
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 558,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 559,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 560,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 560,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 563,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hasEventsManager",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 563,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "try-catch",
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "eventsManager",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 565,
                                                            "char": 35
                                                        },
                                                        "name": "fire",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "dispatch:afterDispatch",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 565,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 565,
                                                                "char": 63
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 565,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 565,
                                                                "char": 69
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 565,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 565,
                                                                "char": 76
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 565,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 566,
                                                    "char": 17
                                                }
                                            ],
                                            "catches": [
                                                {
                                                    "classes": [
                                                        {
                                                            "type": "variable",
                                                            "value": "Exception",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 566,
                                                            "char": 34
                                                        }
                                                    ],
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 577,
                                                        "char": 13
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 571,
                                                                            "char": 29
                                                                        },
                                                                        "name": "handleException",
                                                                        "call-type": 3,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "e",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 571,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 571,
                                                                                "char": 49
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 571,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 571,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 571,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 571,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "finished",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 571,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 571,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 571,
                                                                        "char": 89
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 571,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 571,
                                                                "char": 89
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 573,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 575,
                                                            "char": 25
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "e",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 575,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 576,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 577,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 577,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 578,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 580,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "hasEventsManager",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 580,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "try-catch",
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 584,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "dispatch:afterDispatchLoop",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 584,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 584,
                                                        "char": 63
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 584,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 584,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 584,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 585,
                                            "char": 13
                                        }
                                    ],
                                    "catches": [
                                        {
                                            "classes": [
                                                {
                                                    "type": "variable",
                                                    "value": "Exception",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 585,
                                                    "char": 30
                                                }
                                            ],
                                            "variable": {
                                                "type": "variable",
                                                "value": "e",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 594,
                                                "char": 9
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 587,
                                                                "char": 25
                                                            },
                                                            "name": "handleException",
                                                            "call-type": 3,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "e",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 587,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 587,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 587,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 587,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 587,
                                                        "char": 57
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "return",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 588,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 589,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 592,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "throw",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "e",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 592,
                                                        "char": 24
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 593,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 594,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 594,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 596,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "handler",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 596,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 597,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Process the results of the router by calling into the appropriate\n     * controller action(s) including any routing data or injected parameters.\n     *\n     * @return object|false Returns the dispatched handler class (the Controller for Mvc dispatching or a Task\n     *                      for CLI dispatching) or <tt>false<\/tt> if an exception occurred and the operation was\n     *                      stopped by returning <tt>false<\/tt> in the exception handler.\n     *\n     * @throws \\Exception if any uncaught or unhandled exception occurs during the dispatcher process.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 133,
                                "char": 42
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 133,
                    "last-line": 612,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "forward",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "forward",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 613,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "namespaceName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 615,
                                    "char": 26
                                },
                                {
                                    "variable": "controllerName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 615,
                                    "char": 42
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 615,
                                    "char": 50
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 615,
                                    "char": 62
                                },
                                {
                                    "variable": "taskName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 615,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 617,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 617,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "isControllerInitialize",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 617,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 617,
                                        "char": 52
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 617,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 617,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 617,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "PhalconException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Forwarding inside a controller's initialize() method is forbidden",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 626,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 626,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 626,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 627,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 633,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "previousNamespaceName",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 633,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "namespaceName",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 633,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 633,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 633,
                                    "char": 62
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "previousHandlerName",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 634,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handlerName",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 634,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 634,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 634,
                                    "char": 58
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "previousActionName",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 635,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "actionName",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 635,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 635,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 635,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 638,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "namespaceName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 638,
                                    "char": 52
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "forward",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 638,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "namespace",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 638,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 638,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 638,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "namespaceName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "namespaceName",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 639,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 639,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 640,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 643,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "controllerName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 643,
                                    "char": 54
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "forward",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 643,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "controller",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 643,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 643,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 643,
                                "char": 54
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "handlerName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "controllerName",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 644,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 644,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 645,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "taskName",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 645,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "forward",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 645,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "task",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 645,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 645,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 645,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "handlerName",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "taskName",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 646,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 646,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 647,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 650,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 650,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "actionName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 650,
                                    "char": 46
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "forward",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 650,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "action",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 650,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 650,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 650,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "actionName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "actionName",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 651,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 651,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 652,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 655,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 655,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "forward",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 655,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 655,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 655,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 655,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 656,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 656,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 657,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 659,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "finished",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 659,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 659,
                                    "char": 35
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "forwarded",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 660,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 660,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 661,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Forwards the execution flow to another controller\/action.\n     *\n     * ```php\n     * $this->dispatcher->forward(\n     *     [\n     *         \"controller\" => \"posts\",\n     *         \"action\"     => \"index\",\n     *     ]\n     * );\n     * ```\n     *\n     * @throws \\Phalcon\\Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 614,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 613,
                    "last-line": 665,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 668,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "actionName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 668,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 668,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 669,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the latest dispatched action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 667,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 667,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 666,
                    "last-line": 673,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionSuffix",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 676,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "actionSuffix",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 676,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 676,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 677,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the default action suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 675,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 675,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 674,
                    "last-line": 681,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveMethod",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "activeMethodName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 684,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 686,
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
                                        "value": "activeMethodName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 686,
                                        "char": 77
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 686,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "activeMethodMap",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 686,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 686,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 686,
                                                "char": 64
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "actionName",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 686,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 686,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 686,
                                        "char": 77
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 686,
                                    "char": 77
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 686,
                                "char": 77
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "activeMethodName",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "lcfirst",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 688,
                                                                "char": 22
                                                            },
                                                            "name": "toCamelCase",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 689,
                                                                            "char": 26
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "actionName",
                                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                            "line": 690,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 690,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 690,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 691,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 691,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 691,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 691,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 693,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeMethodMap",
                                            "index-expr": [
                                                {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 693,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "actionName",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 693,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 693,
                                                    "char": 55
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "activeMethodName",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 693,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 693,
                                            "char": 75
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 694,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 696,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "activeMethodName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 696,
                                    "char": 33
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 696,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "actionSuffix",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 696,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 696,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 696,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 697,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current method to be\/executed in the dispatcher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 683,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 683,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 682,
                    "last-line": 712,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBoundModels",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "modelBinder",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 715,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 717,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "modelBinder",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 717,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "modelBinder",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 717,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 717,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 717,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 719,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "modelBinder",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 719,
                                    "char": 25
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 719,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 719,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 720,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 721,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 723,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "modelBinder",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 723,
                                    "char": 28
                                },
                                "name": "getBoundModels",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 723,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 724,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns bound models from binder instance\n     *\n     * ```php\n     * class UserController extends Controller\n     * {\n     *     public function showAction(User $user)\n     *     {\n     *         \/\/ return array with $user\n     *         $boundModels = $this->dispatcher->getBoundModels();\n     *     }\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 714,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 714,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 713,
                    "last-line": 728,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultNamespace",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 731,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "defaultNamespace",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 731,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 731,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 732,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default namespace\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 730,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 730,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 729,
                    "last-line": 736,
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
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 739,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 739,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 739,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 740,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 738,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 738,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 738,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 737,
                    "last-line": 744,
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
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 747,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 747,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 747,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 748,
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
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 746,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 746,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 746,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 745,
                    "last-line": 752,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandlerSuffix",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 755,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handlerSuffix",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 755,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 755,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 756,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the default handler suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 754,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 754,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 753,
                    "last-line": 760,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModelBinder",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 763,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "modelBinder",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 763,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 763,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 764,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets model binder\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BinderInterface",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 761,
                                    "char": 59
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 761,
                                "char": 59
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 762,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 762,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 761,
                    "last-line": 768,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModuleName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 771,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "moduleName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 771,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 771,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 772,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the module where the controller class is\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 770,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 770,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 769,
                    "last-line": 776,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNamespaceName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 779,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "namespaceName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 779,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 779,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 780,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a namespace to be prepended to the current handler name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 778,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 778,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 777,
                    "last-line": 789,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParam",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "param",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 790,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 790,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 790,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 790,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 790,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 792,
                                    "char": 19
                                },
                                {
                                    "variable": "filter",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 792,
                                    "char": 27
                                },
                                {
                                    "variable": "paramValue",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 792,
                                    "char": 39
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 792,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 794,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 794,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 794,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 794,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 794,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 796,
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
                                        "value": "paramValue",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 796,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 796,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "param",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 796,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 796,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 796,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 796,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 797,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 798,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 800,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "filters",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 800,
                                    "char": 22
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 800,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 800,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paramValue",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 801,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 802,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 804,
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
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 804,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 804,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 804,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 804,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 806,
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 806,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 806,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 806,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 806,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 807,
                                            "char": 18
                                        },
                                        "name": "throwDispatchException",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "PhalconException",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "the 'filter' service",
                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                "line": 810,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 810,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 810,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 810,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 812,
                                                        "char": 13
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EXCEPTION_NO_DI",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 812,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 812,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 812,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 812,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 813,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 815,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filter",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "FilterInterface",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 815,
                                            "char": 68
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 815,
                                                "char": 50
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 815,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 815,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 815,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 815,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 815,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 817,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "filter",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 817,
                                    "char": 23
                                },
                                "name": "sanitize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paramValue",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 817,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 817,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "filters",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 817,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 817,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 817,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 818,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a param by its name or numeric index\n     *\n     * @param  mixed param\n     * @param  string|array filters\n     * @param  mixed defaultValue\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 791,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 791,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 790,
                    "last-line": 822,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParams",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 825,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 825,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 825,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 826,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets action params\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 824,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 824,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 823,
                    "last-line": 830,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasParam",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "param",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 831,
                            "char": 39
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
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 833,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 833,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 833,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "param",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 833,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 833,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 833,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 834,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a param exists\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 832,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 832,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 831,
                    "last-line": 839,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isFinished",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 842,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "finished",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 842,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 842,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 843,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if the dispatch loop is finished or has more pendent\n     * controllers\/tasks to dispatch\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 841,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 841,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 840,
                    "last-line": 847,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setActionName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 848,
                            "char": 52
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
                                    "property": "actionName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 850,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 850,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 851,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the action name to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 849,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 848,
                    "last-line": 856,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultAction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 857,
                            "char": 55
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
                                    "property": "defaultAction",
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 859,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 859,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 860,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 858,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 857,
                    "last-line": 864,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultNamespace",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "namespaceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 865,
                            "char": 61
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
                                    "property": "defaultNamespace",
                                    "expr": {
                                        "type": "variable",
                                        "value": "namespaceName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 867,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 867,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 868,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default namespace\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 866,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 865,
                    "last-line": 872,
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
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 873,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 873,
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
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 875,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 875,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 876,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 874,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 873,
                    "last-line": 880,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandlerClass",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "handlerSuffix",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 883,
                                    "char": 26
                                },
                                {
                                    "variable": "handlerName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 883,
                                    "char": 39
                                },
                                {
                                    "variable": "namespaceName",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 883,
                                    "char": 54
                                },
                                {
                                    "variable": "camelizedClass",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 883,
                                    "char": 70
                                },
                                {
                                    "variable": "handlerClass",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 884,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 886,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 886,
                                    "char": 14
                                },
                                "name": "resolveEmptyProperties",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 886,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 888,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handlerSuffix",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 888,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handlerSuffix",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 888,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 888,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 888,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handlerName",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 889,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handlerName",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 889,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 889,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 889,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "namespaceName",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 890,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "namespaceName",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 890,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 890,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 890,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 893,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "memstr",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "handlerName",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 893,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 893,
                                            "char": 31
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "\\\\",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 893,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 893,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 893,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 893,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "camelizedClass",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 894,
                                                    "char": 39
                                                },
                                                "name": "toCamelCase",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "handlerName",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 894,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 894,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 894,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 894,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 895,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "camelizedClass",
                                            "expr": {
                                                "type": "variable",
                                                "value": "handlerName",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 896,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 896,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 897,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 900,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "namespaceName",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 900,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fcall",
                                            "name": "ends_with",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "namespaceName",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 901,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 901,
                                                    "char": 40
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "\\\\",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 901,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 901,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 901,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 901,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "namespaceName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "\\\\",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 902,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 902,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 903,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 905,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handlerClass",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "namespaceName",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 905,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "camelizedClass",
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 905,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 905,
                                                    "char": 63
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "handlerSuffix",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 905,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 905,
                                                "char": 78
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 905,
                                            "char": 78
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 906,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handlerClass",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "camelizedClass",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 907,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "handlerSuffix",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 907,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 907,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 907,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 908,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 910,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "handlerClass",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 910,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 911,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Possible class name that will be located to dispatch the request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 882,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 882,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 881,
                    "last-line": 915,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setParam",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "param",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 916,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 916,
                            "char": 50
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
                                    "property": "params",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "param",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 918,
                                            "char": 31
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 918,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 918,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 919,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set a param by its name or numeric index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 917,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 916,
                    "last-line": 923,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setParams",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 924,
                            "char": 43
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
                                    "property": "params",
                                    "expr": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 926,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 926,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 927,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets action params to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 925,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 924,
                    "last-line": 931,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setReturnedValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 932,
                            "char": 47
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
                                    "property": "returnedValue",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 934,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 934,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 935,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the latest returned value by an action manually\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 933,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 932,
                    "last-line": 939,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setActionSuffix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "actionSuffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 940,
                            "char": 56
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
                                    "property": "actionSuffix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionSuffix",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 942,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 942,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 943,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default action suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 941,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 940,
                    "last-line": 947,
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
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 948,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 948,
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
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 950,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 950,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 951,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 949,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 948,
                    "last-line": 955,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHandlerSuffix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handlerSuffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 956,
                            "char": 58
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
                                    "property": "handlerSuffix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "handlerSuffix",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 958,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 958,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 959,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default suffix for the handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 957,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 956,
                    "last-line": 979,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setModelBinder",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelBinder",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "BinderInterface",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 980,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 980,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "cache",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 980,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 980,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 982,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 984,
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
                                        "value": "cache",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 984,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 984,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 984,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 984,
                                "char": 35
                            },
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 985,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 985,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 985,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 985,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 987,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "cache",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 987,
                                                    "char": 35
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "cache",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 987,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 987,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 987,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 987,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 988,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 990,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "cache",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 990,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 990,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 990,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "modelBinder",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 991,
                                            "char": 25
                                        },
                                        "name": "setCache",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cache",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 991,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 991,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 991,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 992,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 994,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "modelBinding",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 994,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 994,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 995,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "modelBinder",
                                    "expr": {
                                        "type": "variable",
                                        "value": "modelBinder",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 995,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 995,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 997,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 997,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 998,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Enable model binding during dispatch\n     *\n     * ```php\n     * $di->set(\n     *     'dispatcher',\n     *     function() {\n     *         $dispatcher = new Dispatcher();\n     *\n     *         $dispatcher->setModelBinder(\n     *             new Binder(),\n     *             'cache'\n     *         );\n     *\n     *         return $dispatcher;\n     *     }\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Dispatcher",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 981,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 981,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 981,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 980,
                    "last-line": 1002,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setModuleName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "moduleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1003,
                            "char": 52
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
                                    "property": "moduleName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "moduleName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1005,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1005,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1006,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the module where the controller is (only informative)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 1004,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 1003,
                    "last-line": 1010,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setNamespaceName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "namespaceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1011,
                            "char": 58
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
                                    "property": "namespaceName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "namespaceName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1013,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1013,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1014,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the namespace where the controller class is\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 1012,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 1011,
                    "last-line": 1018,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReturnedValue",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1021,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "returnedValue",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1021,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1021,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1022,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns value returned by the latest dispatched action\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1020,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 1020,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 1019,
                    "last-line": 1026,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "wasForwarded",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1029,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "forwarded",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1029,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1029,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1030,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the current executed action was forwarded by another one\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1028,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 1028,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 1027,
                    "last-line": 1034,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "resolveEmptyProperties",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1038,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "namespaceName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1038,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1038,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1038,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "namespaceName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 1039,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultNamespace",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 1039,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 1039,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 1039,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1040,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1043,
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
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1043,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "handlerName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1043,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1043,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1043,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "handlerName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 1044,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultHandler",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 1044,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 1044,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 1044,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1045,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1048,
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
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1048,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "actionName",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1048,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1048,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1048,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "actionName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 1049,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultAction",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 1049,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 1049,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 1049,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1050,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1051,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set empty properties to their defaults (where defaults are available)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 1036,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 1035,
                    "last-line": 1053,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "toCamelCase",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "input",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1053,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "camelCaseInput",
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1055,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1057,
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
                                        "value": "camelCaseInput",
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1057,
                                        "char": 61
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 1057,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "camelCaseMap",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 1057,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 1057,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "input",
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 1057,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                        "line": 1057,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1057,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1057,
                                "char": 61
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "camelCaseInput",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "",
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 1059,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 1059,
                                                        "char": 17
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "array_map",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "ucfirst",
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 1061,
                                                                        "char": 28
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 1061,
                                                                    "char": 28
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "fcall",
                                                                        "name": "preg_split",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "\/[_-]+\/",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 1062,
                                                                                    "char": 39
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 1062,
                                                                                "char": 39
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "input",
                                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                    "line": 1062,
                                                                                    "char": 46
                                                                                },
                                                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                                "line": 1062,
                                                                                "char": 46
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                        "line": 1063,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                                    "line": 1063,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                                            "line": 1064,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Dispatcher.zep",
                                                        "line": 1064,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 1064,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 1064,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1066,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "camelCaseMap",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "input",
                                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                                    "line": 1066,
                                                    "char": 41
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "camelCaseInput",
                                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                                "line": 1066,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Dispatcher.zep",
                                            "line": 1066,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Dispatcher.zep",
                                    "line": 1067,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1069,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "camelCaseInput",
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1069,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Dispatcher.zep",
                            "line": 1070,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Dispatcher.zep",
                                "line": 1054,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 1054,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 1053,
                    "last-line": 1071,
                    "char": 22
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "EXCEPTION_ACTION_NOT_FOUND",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 31,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 32,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "EXCEPTION_CYCLIC_ROUTING",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 32,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 33,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "EXCEPTION_HANDLER_NOT_FOUND",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 33,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 34,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "EXCEPTION_INVALID_HANDLER",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 34,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 35,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "EXCEPTION_INVALID_PARAMS",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 35,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 36,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "EXCEPTION_NO_DI",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Dispatcher.zep",
                        "line": 36,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Dispatcher.zep",
                    "line": 38,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Dispatcher.zep",
            "line": 29,
            "char": 14
        },
        "file": "\/app\/phalcon\/Dispatcher.zep",
        "line": 29,
        "char": 14
    }
]