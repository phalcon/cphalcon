[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/DispatcherInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/DispatcherInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Dispatcher\n *",
        "file": "\/app\/phalcon\/DispatcherInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "DispatcherInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dispatch",
                    "docblock": "**\n     * Dispatches a handle action taking into account the routing parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 21,
                                "char": 43
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 21,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 21,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 21,
                    "last-line": 25,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 26,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Forwards the execution flow to another controller\/action\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 26,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionName",
                    "docblock": "**\n     * Gets last dispatched action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 31,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 31,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionSuffix",
                    "docblock": "**\n     * Gets the default action suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 36,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 36,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandlerSuffix",
                    "docblock": "**\n     * Gets the default handler suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 41,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 41,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 41,
                    "last-line": 47,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 48,
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
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 48,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 48,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Gets a param by its name or numeric index\n     *\n     * @param  string|array filters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 48,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 48,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParams",
                    "docblock": "**\n     * Gets action params\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 53,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 53,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReturnedValue",
                    "docblock": "**\n     * Returns value returned by the latest dispatched action\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 58,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 58,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 58,
                    "last-line": 62,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 63,
                            "char": 39
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
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 63,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 63,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 63,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isFinished",
                    "docblock": "**\n     * Checks if the dispatch loop is finished or has more pendent\n     * controllers\/tasks to dispatch\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DispatcherInterface.zep",
                                "line": 69,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 69,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 69,
                    "last-line": 73,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 74,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Sets the action name to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 74,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 74,
                    "last-line": 78,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 79,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Sets the default action suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 79,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 79,
                    "last-line": 83,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 84,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Sets the default action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 84,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 84,
                    "last-line": 88,
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
                            "name": "defaultNamespace",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 89,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Sets the default namespace\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 89,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 89,
                    "last-line": 93,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 94,
                            "char": 58
                        }
                    ],
                    "docblock": "**\n     * Sets the default suffix for the handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 94,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 94,
                    "last-line": 98,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 99,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Sets the module name which the application belongs to\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 99,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 99,
                    "last-line": 103,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 104,
                            "char": 58
                        }
                    ],
                    "docblock": "**\n     * Sets the namespace which the controller belongs to\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 104,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 104,
                    "last-line": 110,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 111,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 111,
                            "char": 46
                        }
                    ],
                    "docblock": "**\n     * Set a param by its name or numeric index\n     *\n     * @param  mixed value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 111,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 111,
                    "last-line": 115,
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
                            "file": "\/app\/phalcon\/DispatcherInterface.zep",
                            "line": 116,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Sets action params to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DispatcherInterface.zep",
                        "line": 116,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/DispatcherInterface.zep",
                    "line": 116,
                    "last-line": 117,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/DispatcherInterface.zep",
            "line": 117,
            "char": 1
        },
        "file": "\/app\/phalcon\/DispatcherInterface.zep",
        "line": 0,
        "char": 0
    }
]