[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\View\\Engine",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ViewBaseInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Mvc\\View engine adapters\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "interface",
        "name": "EngineInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContent",
                    "docblock": "**\n     * Returns cached output on another view stage\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                                "line": 24,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                        "line": 24,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                    "line": 24,
                    "last-line": 28,
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
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                            "line": 29,
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
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                                "line": 29,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                            "line": 29,
                            "char": 67
                        }
                    ],
                    "docblock": "**\n     * Renders a partial inside another view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                                "line": 29,
                                "char": 78
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                        "line": 29,
                        "char": 78
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                    "line": 29,
                    "last-line": 33,
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
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                            "line": 34,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                            "line": 34,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "mustClean",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                                "line": 34,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                            "line": 34,
                            "char": 75
                        }
                    ],
                    "docblock": "**\n     * Renders a view using the template engine\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
                    "line": 34,
                    "last-line": 35,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
            "line": 35,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/EngineInterface.zep",
        "line": 0,
        "char": 0
    }
]