[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cli\\Router",
        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Cli\\Router\\Route\n *",
        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "RouteInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "compilePattern",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                            "line": 22,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Replaces placeholders from pattern returning a valid PCRE regular\n     * expression\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 22,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 22,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 22,
                    "last-line": 26,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "delimiter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 27,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                            "line": 27,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Set the routing delimiter\n     *",
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 27,
                    "last-line": 31,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCompiledPattern",
                    "docblock": "**\n     * Returns the route's pattern\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 32,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 32,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 32,
                    "last-line": 36,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getDelimiter",
                    "docblock": "**\n     * Get routing delimiter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 37,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 37,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 37,
                    "last-line": 41,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDescription",
                    "docblock": "**\n     * Returns the route's description\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 42,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 42,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 42,
                    "last-line": 46,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "docblock": "**\n     * Returns the route's name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 47,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 47,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 47,
                    "last-line": 51,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPaths",
                    "docblock": "**\n     * Returns the paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 52,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 52,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 52,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPattern",
                    "docblock": "**\n     * Returns the route's pattern\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 57,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 57,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 57,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReversedPaths",
                    "docblock": "**\n     * Returns the paths using positions as keys and names as values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 62,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 62,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 62,
                    "last-line": 66,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRouteId",
                    "docblock": "**\n     * Returns the route's id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 67,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 67,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 67,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reConfigure",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                            "line": 72,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 72,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                            "line": 72,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Reconfigure the route adding a new pattern and a set of paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 72,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 72,
                    "last-line": 76,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "reset",
                    "docblock": "**\n     * Resets the internal route id generator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 77,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 77,
                    "last-line": 81,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDescription",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "description",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                            "line": 82,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Sets the route's description\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                    "line": 82,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 82,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 82,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 82,
                    "last-line": 86,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                            "line": 87,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Sets the route's name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                    "line": 87,
                                    "char": 61
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                                "line": 87,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                        "line": 87,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
                    "line": 87,
                    "last-line": 88,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
            "line": 88,
            "char": 1
        },
        "file": "\/app\/phalcon\/Cli\/Router\/RouteInterface.zep",
        "line": 0,
        "char": 0
    }
]