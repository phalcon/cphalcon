[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cli",
        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cli\\Router\\RouteInterface",
                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Cli\\Router\n *",
        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "RouterInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "add",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 23,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 23,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 23,
                            "char": 58
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router on any HTTP method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                    "line": 23,
                                    "char": 79
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 23,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 23,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionName",
                    "docblock": "**\n     * Returns processed action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 28,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 28,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMatchedRoute",
                    "docblock": "**\n     * Returns the route that matches the handled URI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                    "line": 33,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 33,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 33,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMatches",
                    "docblock": "**\n     * Return the sub expressions in the regular expression matched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 38,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 38,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModuleName",
                    "docblock": "**\n     * Returns processed module name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 43,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 43,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParams",
                    "docblock": "**\n     * Returns processed extra params\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 48,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 48,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRouteById",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 53,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Returns a route object by its id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                    "line": 53,
                                    "char": 61
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 53,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 53,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRouteByName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 58,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Returns a route object by its name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                    "line": 58,
                                    "char": 69
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 58,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 58,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 58,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRoutes",
                    "docblock": "**\n     * Return all the routes defined in the router\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                    "line": 63,
                                    "char": 54
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 63,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 63,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 63,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTaskName",
                    "docblock": "**\n     * Returns processed task name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 68,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 68,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 68,
                    "last-line": 74,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "handle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 75,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 75,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Handles routing information received from the rewrite engine\n     *\n     * @param array arguments\n     *",
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 75,
                    "last-line": 79,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 80,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Sets the default action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 80,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 80,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultModule",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "moduleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 85,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Sets the name of the default module\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 85,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 85,
                    "last-line": 89,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaults",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "defaults",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 90,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Sets an array of default paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 90,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 90,
                    "last-line": 94,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                            "line": 95,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Sets the default task name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 95,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 95,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "wasMatched",
                    "docblock": "**\n     * Check if the router matches any of the defined routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                                "line": 100,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                        "line": 100,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
                    "line": 100,
                    "last-line": 101,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
            "line": 101,
            "char": 1
        },
        "file": "\/app\/phalcon\/Cli\/RouterInterface.zep",
        "line": 0,
        "char": 0
    }
]