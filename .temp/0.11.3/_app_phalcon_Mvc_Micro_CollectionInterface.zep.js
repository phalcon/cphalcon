[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Micro",
        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Micro\\CollectionInterface\n *\n * Interface for Phalcon\\Mvc\\Micro\\Collection\n *",
        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "CollectionInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 23,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 23,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 23,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 23,
                            "char": 86
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is DELETE\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 23,
                                    "char": 112
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 23,
                                "char": 112
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 23,
                        "char": 112
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 28,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 28,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 28,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 28,
                            "char": 83
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is GET\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 28,
                                    "char": 109
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 28,
                                "char": 109
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 28,
                        "char": 109
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandler",
                    "docblock": "**\n     * Returns the main handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 33,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 33,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandlers",
                    "docblock": "**\n     * Returns the registered handlers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 38,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 38,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrefix",
                    "docblock": "**\n     * Returns the collection prefix if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 43,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 43,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "head",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 48,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 48,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 48,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 48,
                            "char": 84
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is HEAD\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 48,
                                    "char": 110
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 48,
                                "char": 110
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 48,
                        "char": 110
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isLazy",
                    "docblock": "**\n     * Returns if the main handler must be lazy loaded\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 53,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 53,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "map",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 58,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 58,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 58,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 58,
                            "char": 83
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 58,
                                    "char": 109
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 58,
                                "char": 109
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 58,
                        "char": 109
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 58,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "options",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 63,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 63,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 63,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 63,
                            "char": 87
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is OPTIONS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 63,
                                    "char": 113
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 63,
                                "char": 113
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 63,
                        "char": 113
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 63,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "patch",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 68,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 68,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 68,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 68,
                            "char": 85
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is PATCH\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 68,
                                    "char": 111
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 68,
                                "char": 111
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 68,
                        "char": 111
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 68,
                    "last-line": 72,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "post",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 73,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 73,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 73,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 73,
                            "char": 84
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is POST\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 73,
                                    "char": 110
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 73,
                                "char": 110
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 73,
                        "char": 110
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 73,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "put",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 78,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 78,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 78,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 78,
                            "char": 83
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is PUT\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 78,
                                    "char": 109
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 78,
                                "char": 109
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 78,
                        "char": 109
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 78,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHandler",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 83,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "lazy",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 83,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 83,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Sets the main handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 83,
                                    "char": 88
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 83,
                                "char": 88
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 83,
                        "char": 88
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 83,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLazy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "lazy",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 88,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Sets if the main handler must be lazy loaded\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 88,
                                    "char": 65
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 88,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 88,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 88,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPrefix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "prefix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                            "line": 93,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets a prefix for all routes added to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                    "line": 93,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                                "line": 93,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                        "line": 93,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
                    "line": 93,
                    "last-line": 94,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
            "line": 94,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Micro\/CollectionInterface.zep",
        "line": 0,
        "char": 0
    }
]