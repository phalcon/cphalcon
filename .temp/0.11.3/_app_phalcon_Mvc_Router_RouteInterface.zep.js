[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Router",
        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Router\\RouteInterface\n *\n * Interface for Phalcon\\Mvc\\Router\\Route\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
        "line": 18,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 23,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Replaces placeholders from pattern returning a valid PCRE regular expression\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 23,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 23,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "convert",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 28,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "converter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 28,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Adds a converter to perform an additional transformation for certain parameter.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                    "line": 28,
                                    "char": 77
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 28,
                                "char": 77
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 28,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 33,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 33,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHostname",
                    "docblock": "**\n     * Returns the hostname restriction if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 38,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 38,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHttpMethods",
                    "docblock": "**\n     * Returns the HTTP methods that constraint matching the route\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 43,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 43,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 43,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 43,
                    "last-line": 47,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 48,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 48,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 48,
                    "last-line": 52,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 53,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 53,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 53,
                    "last-line": 57,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 58,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 58,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 58,
                    "last-line": 62,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 63,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 63,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 63,
                    "last-line": 67,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 68,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 68,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 68,
                    "last-line": 72,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHostname",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "hostname",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 73,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Sets a hostname restriction to the route\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                    "line": 73,
                                    "char": 69
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 73,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 73,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 73,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHttpMethods",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "httpMethods",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 78,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets a set of HTTP methods that constraint the matching of the route\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                    "line": 78,
                                    "char": 72
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 78,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 78,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 78,
                    "last-line": 82,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 83,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Sets the route's name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 83,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 83,
                    "last-line": 87,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 88,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                                "line": 88,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 88,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Reconfigure the route adding a new pattern and a set of paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 88,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 88,
                    "last-line": 92,
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
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 93,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 93,
                    "last-line": 97,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "via",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "httpMethods",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                            "line": 98,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Set one or more HTTP methods that constraint the matching of the route\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                        "line": 98,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
                    "line": 98,
                    "last-line": 99,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
            "line": 99,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Router\/RouteInterface.zep",
        "line": 0,
        "char": 0
    }
]