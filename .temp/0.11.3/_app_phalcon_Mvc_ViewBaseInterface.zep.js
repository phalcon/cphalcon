[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                "line": 13,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\ViewInterface\n *\n * Interface for Phalcon\\Mvc\\View and Phalcon\\Mvc\\View\\Simple\n *",
        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ViewBaseInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContent",
                    "docblock": "**\n     * Returns cached output from another view stage\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                                "line": 25,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                        "line": 25,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParamsToView",
                    "docblock": "**\n     * Returns parameters to views\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                                "line": 30,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                        "line": 30,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getViewsDir",
                    "docblock": "**\n     * Gets views directory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                                "line": 35,
                                "char": 45
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                                "line": 35,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                        "line": 35,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "partial",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "partialPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 40,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                                "line": 40,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 40,
                            "char": 67
                        }
                    ],
                    "docblock": "**\n     * Renders a partial view\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 40,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 45,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Externally sets the view content\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 45,
                    "last-line": 49,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setParamToView",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 50,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 50,
                            "char": 58
                        }
                    ],
                    "docblock": "**\n     * Adds parameters to views (alias of setVar)\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 50,
                    "last-line": 54,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setVar",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 55,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 55,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Adds parameters to views\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 55,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setViewsDir",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "viewsDir",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                            "line": 61,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets views directory. Depending of your platform, always add a trailing\n     * slash or backslash\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
                    "line": 61,
                    "last-line": 63,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
            "line": 63,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/ViewBaseInterface.zep",
        "line": 0,
        "char": 0
    }
]