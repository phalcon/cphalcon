[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cli",
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cli\\Dispatcher\\Exception",
                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                "line": 13,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Dispatcher",
                "alias": "CliDispatcher",
                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                "line": 14,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                "line": 15,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\FilterInterface",
                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                "line": 16,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 39,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Dispatching is the process of taking the command-line arguments, extracting\n * the module name, task name, action name, and optional parameters contained in\n * it, and then instantiating a task and calling an action on it.\n *\n * ```php\n * use Phalcon\\Di;\n * use Phalcon\\Cli\\Dispatcher;\n *\n * $di = new Di();\n *\n * $dispatcher = new Dispatcher();\n *\n * $dispatcher->setDi($di);\n *\n * $dispatcher->setTaskName(\"posts\");\n * $dispatcher->setActionName(\"index\");\n * $dispatcher->setParams([]);\n *\n * $handle = $dispatcher->dispatch();\n * ```\n *",
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 40,
        "char": 5
    },
    {
        "type": "class",
        "name": "Dispatcher",
        "abstract": 0,
        "final": 0,
        "extends": "CliDispatcher",
        "implements": [
            {
                "type": "variable",
                "value": "DispatcherInterface",
                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                "line": 41,
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
                    "name": "defaultHandler",
                    "default": {
                        "type": "string",
                        "value": "main",
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 45,
                        "char": 36
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 49,
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
                        "value": "main",
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 50,
                        "char": 35
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 54,
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
                        "value": "Task",
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 55,
                        "char": 35
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 59,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 60,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 64,
                    "char": 6
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
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 65,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "actionMethod",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 65,
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
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 65,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 65,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 67,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 71,
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
                                        "type": "fcall",
                                        "name": "array_values",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 71,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 71,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 71,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 71,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 72,
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
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 72,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 72,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 72,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "options",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 72,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 72,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 72,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 72,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 72,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 74,
                            "char": 14
                        },
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
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 75,
                                                        "char": 21
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 75,
                                                    "char": 21
                                                },
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "actionMethod",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 75,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 75,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 75,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 75,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 77,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 77,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 77,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 78,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Calls the action method.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 66,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 66,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 65,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveTask",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 85,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "activeHandler",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 85,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 85,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 86,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the active task in the dispatcher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TaskInterface",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 84,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 84,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 84,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 83,
                    "last-line": 90,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastTask",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 93,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "lastHandler",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 93,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 93,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 94,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the latest dispatched controller\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TaskInterface",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 92,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 92,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 92,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 91,
                    "last-line": 102,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 103,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 103,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 103,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 103,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 103,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 105,
                                    "char": 20
                                },
                                {
                                    "variable": "filter",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 105,
                                    "char": 28
                                },
                                {
                                    "variable": "optionValue",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 105,
                                    "char": 41
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 105,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 107,
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
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 107,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 107,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 107,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 107,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 109,
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
                                        "value": "optionValue",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 109,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 109,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "option",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 109,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 109,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 109,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 109,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 110,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 111,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 113,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "filters",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 113,
                                    "char": 22
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 113,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 113,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "optionValue",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 114,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 115,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 117,
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
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 117,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 117,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 117,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 117,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 119,
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
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 119,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 119,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 119,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 119,
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
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 120,
                                            "char": 18
                                        },
                                        "name": "throwDispatchException",
                                        "call-type": 3,
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
                                                                "value": "the 'filter' service",
                                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                                "line": 121,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                            "line": 121,
                                                            "char": 73
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 121,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 121,
                                                "char": 74
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "CliDispatcher",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 123,
                                                        "char": 13
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EXCEPTION_NO_DI",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 123,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 123,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 123,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 123,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 124,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 126,
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
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 126,
                                            "char": 68
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 126,
                                                "char": 50
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 126,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 126,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 126,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 126,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 126,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 128,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "filter",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 128,
                                    "char": 23
                                },
                                "name": "sanitize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "optionValue",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 128,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 128,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "filters",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 128,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 128,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 128,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets an option by its name or numeric index\n     *\n     * @param  mixed $option\n     * @param  string|array $filters\n     * @param  mixed $defaultValue\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 104,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 104,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 103,
                    "last-line": 133,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 136,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 136,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 136,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 137,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get dispatched options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 134,
                    "last-line": 141,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTaskName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 144,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handlerName",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 144,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 144,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 145,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets last dispatched task name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 143,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 143,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 142,
                    "last-line": 149,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTaskSuffix",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 152,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handlerSuffix",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 152,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 152,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 153,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the default task suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 151,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 151,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 150,
                    "last-line": 157,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 158,
                            "char": 41
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
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 160,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 160,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 160,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "option",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 160,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 160,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 160,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 161,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if an option exists\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 159,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 158,
                    "last-line": 165,
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
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 166,
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
                                    "property": "defaultHandler",
                                    "expr": {
                                        "type": "variable",
                                        "value": "taskName",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 168,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 168,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 169,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default task name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 167,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 166,
                    "last-line": 173,
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
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 174,
                            "char": 45
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
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 176,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 176,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 177,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the options to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 174,
                    "last-line": 181,
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
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 182,
                            "char": 48
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
                                    "property": "handlerName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "taskName",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 184,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 184,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 185,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the task name to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 183,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 182,
                    "last-line": 189,
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
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 190,
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
                                    "property": "handlerSuffix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "taskSuffix",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 192,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 192,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 193,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default task suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                        "line": 191,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 190,
                    "last-line": 197,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "handleException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "exception",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "\\Exception",
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 198,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 198,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 200,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 202,
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
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 202,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 202,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 202,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 202,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 202,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 202,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 204,
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
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 204,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 204,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 204,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 204,
                                "char": 43
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
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 205,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "dispatch:beforeException",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 205,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 205,
                                                    "char": 60
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 205,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 205,
                                                    "char": 66
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "exception",
                                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                        "line": 205,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 205,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 205,
                                            "char": 81
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 205,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 205,
                                        "char": 89
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 206,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 207,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 208,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 209,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Handles a user exception\n     *",
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 198,
                    "last-line": 213,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "throwDispatchException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 214,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "exceptionCode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 214,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 214,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "exception",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 216,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 218,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "exception",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 218,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 218,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "exceptionCode",
                                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                    "line": 218,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 218,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 218,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 218,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 220,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 220,
                                        "char": 17
                                    },
                                    "name": "handleException",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "exception",
                                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                                "line": 220,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                            "line": 220,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 220,
                                    "char": 47
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 220,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 220,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                        "line": 221,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                    "line": 222,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 224,
                            "char": 13
                        },
                        {
                            "type": "throw",
                            "expr": {
                                "type": "variable",
                                "value": "exception",
                                "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                                "line": 224,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                            "line": 225,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Throws an internal exception\n     *",
                    "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
                    "line": 214,
                    "last-line": 226,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
            "line": 40,
            "char": 5
        },
        "file": "\/app\/phalcon\/Cli\/Dispatcher.zep",
        "line": 40,
        "char": 5
    }
]