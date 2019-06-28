[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\ViewInterface\n *\n * Interface for Phalcon\\Mvc\\View\n *",
        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ViewInterface",
        "extends": [
            {
                "type": "variable",
                "value": "ViewBaseInterface",
                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
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
                    "name": "cleanTemplateAfter",
                    "docblock": "**\n     * Resets any template before layouts\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "cleanTemplateBefore",
                    "docblock": "**\n     * Resets any template before layouts\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "disable",
                    "docblock": "**\n     * Disables the auto-rendering process\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "enable",
                    "docblock": "**\n     * Enables the auto-rendering process\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "finish",
                    "docblock": "**\n     * Finishes the render process by stopping the output buffering\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionName",
                    "docblock": "**\n     * Gets the name of the action rendered\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 48,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 48,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveRenderPath",
                    "docblock": "**\n     * Returns the path of the view that is currently rendered\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 53,
                                "char": 53
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 53,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 53,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBasePath",
                    "docblock": "**\n     * Gets base path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 58,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 58,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 58,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getControllerName",
                    "docblock": "**\n     * Gets the name of the controller rendered\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 63,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 63,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 63,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLayout",
                    "docblock": "**\n     * Returns the name of the main view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 68,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 68,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 68,
                    "last-line": 72,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLayoutsDir",
                    "docblock": "**\n     * Gets the current layouts sub-directory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 73,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 73,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 73,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMainView",
                    "docblock": "**\n     * Returns the name of the main view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 78,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 78,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 78,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPartialsDir",
                    "docblock": "**\n     * Gets the current partials sub-directory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 83,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 83,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 83,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isDisabled",
                    "docblock": "**\n     * Whether the automatic rendering is disabled\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 88,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 88,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 88,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "pick",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "renderView",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 93,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Choose a view different to render than last-controller\/last-action\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 93,
                    "last-line": 97,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerEngines",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "engines",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 98,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Register templating engines\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 98,
                    "last-line": 102,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 103,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 103,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 103,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 103,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Executes render process from dispatching data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ViewInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                    "line": 103,
                                    "char": 110
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 103,
                                "char": 110
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 103,
                                "char": 116
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 103,
                        "char": 116
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 103,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "docblock": "**\n     * Resets the view component to its factory default values\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 108,
                    "last-line": 113,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBasePath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "basePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 114,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets base path. Depending of your platform, always add a trailing slash\n     * or backslash\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 114,
                    "last-line": 119,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLayout",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "layout",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 120,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Change the layout to be used instead of using the name of the latest\n     * controller name\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 120,
                    "last-line": 126,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLayoutsDir",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "layoutsDir",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 127,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Sets the layouts sub-directory. Must be a directory under the views\n     * directory. Depending of your platform, always add a trailing slash or\n     * backslash\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 127,
                    "last-line": 132,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMainView",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "viewPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 133,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets default view name. Must be a file without extension in the views\n     * directory\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 133,
                    "last-line": 139,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPartialsDir",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "partialsDir",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 140,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Sets a partials sub-directory. Must be a directory under the views\n     * directory. Depending of your platform, always add a trailing slash or\n     * backslash\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 140,
                    "last-line": 144,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRenderLevel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "level",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 145,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets the render level for the view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ViewInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                    "line": 145,
                                    "char": 65
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                                "line": 145,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                        "line": 145,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 145,
                    "last-line": 151,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTemplateAfter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "templateAfter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 152,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Appends template after controller layout\n     *\n     * @param string|array templateAfter\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 152,
                    "last-line": 158,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTemplateBefore",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "templateBefore",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                            "line": 159,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Appends template before controller layout\n     *\n     * @param string|array templateBefore\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 159,
                    "last-line": 163,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "start",
                    "docblock": "**\n     * Starts rendering process enabling the output buffering\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
                    "line": 164,
                    "last-line": 165,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
            "line": 165,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/ViewInterface.zep",
        "line": 0,
        "char": 0
    }
]