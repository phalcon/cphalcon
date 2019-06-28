[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router",
                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\RouteInterface",
                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                "line": 14,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\GroupInterface",
                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                "line": 15,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Mvc\\Router\n *",
        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
        "line": 20,
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
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 25,
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
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 25,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 25,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "httpMethods",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 25,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 25,
                            "char": 82
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
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 25,
                                    "char": 103
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 25,
                                "char": 103
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 25,
                        "char": 103
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "attach",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "route",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "RouteInterface",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 30,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 30,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "Router",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 30,
                                    "char": 88
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 30,
                                    "char": 88
                                },
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 30,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 30,
                            "char": 88
                        }
                    ],
                    "docblock": "**\n     * Attach Route object to the routes stack.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 30,
                                    "char": 110
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 30,
                                "char": 110
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 30,
                        "char": 110
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addConnect",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 35,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 35,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 35,
                            "char": 65
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is CONNECT\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 35,
                                    "char": 86
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 35,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 35,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addDelete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 40,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 40,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 40,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is DELETE\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 40,
                                    "char": 85
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 40,
                                "char": 85
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 40,
                        "char": 85
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 40,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addHead",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 45,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 45,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 45,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is HEAD\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 45,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 45,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 45,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 45,
                    "last-line": 49,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 50,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 50,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 50,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is GET\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 50,
                                    "char": 82
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 50,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 50,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 50,
                    "last-line": 54,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 55,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 55,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 55,
                            "char": 65
                        }
                    ],
                    "docblock": "**\n     * Add a route to the router that only match if the HTTP method is OPTIONS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 55,
                                    "char": 86
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 55,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 55,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 55,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addPatch",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 60,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 60,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 60,
                            "char": 59
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is PATCH\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 60,
                                    "char": 80
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 60,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 60,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 60,
                    "last-line": 64,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addPost",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 65,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 65,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 65,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is POST\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 65,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 65,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 65,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 65,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addPurge",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 71,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 71,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 71,
                            "char": 63
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is PURGE\n     * (Squid and Varnish support)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 71,
                                    "char": 84
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 71,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 71,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 71,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addPut",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 76,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 76,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 76,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is PUT\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 76,
                                    "char": 82
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 76,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 76,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addTrace",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 81,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 81,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 81,
                            "char": 63
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is TRACE\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 81,
                                    "char": 84
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 81,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 81,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 81,
                    "last-line": 85,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "docblock": "**\n     * Removes all the defined routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 86,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 86,
                    "last-line": 90,
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
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 91,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 91,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 91,
                    "last-line": 95,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getControllerName",
                    "docblock": "**\n     * Returns processed controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 96,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 96,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 96,
                    "last-line": 100,
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
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 101,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 101,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 101,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 101,
                    "last-line": 105,
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
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 106,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 106,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 106,
                    "last-line": 110,
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
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 111,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 111,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 111,
                    "last-line": 115,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNamespaceName",
                    "docblock": "**\n     * Returns processed namespace name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 116,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 116,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 116,
                    "last-line": 120,
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
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 121,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 121,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 121,
                    "last-line": 125,
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
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 126,
                                    "char": 54
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 126,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 126,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 126,
                    "last-line": 130,
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
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 131,
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
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 131,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 131,
                                "char": 62
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 131,
                                "char": 68
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 131,
                        "char": 68
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 131,
                    "last-line": 135,
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
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 136,
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
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 136,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 136,
                                "char": 70
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 136,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 136,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 136,
                    "last-line": 140,
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
                            "name": "uri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 141,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Handles routing information received from the rewrite engine\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 141,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 141,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "mount",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "group",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "GroupInterface",
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 146,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 146,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Mounts a group of routes in the router\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                    "line": 146,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 146,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 146,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 146,
                    "last-line": 150,
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
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 151,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Sets the default action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 151,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 151,
                    "last-line": 155,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultController",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 156,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Sets the default controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 156,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 156,
                    "last-line": 160,
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
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 161,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Sets the name of the default module\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 161,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 161,
                    "last-line": 165,
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
                            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                            "line": 166,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Sets an array of default paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 166,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 166,
                    "last-line": 170,
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
                                "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                                "line": 171,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                        "line": 171,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
                    "line": 171,
                    "last-line": 172,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
            "line": 172,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/RouterInterface.zep",
        "line": 0,
        "char": 0
    }
]