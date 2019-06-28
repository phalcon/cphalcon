[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Router",
        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\RouteInterface",
                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
        "line": 60,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Router\\GroupInterface\n *\n *```php\n * $router = new \\Phalcon\\Mvc\\Router();\n *\n * \/\/ Create a group with a common module and controller\n * $blog = new Group(\n *     [\n *         \"module\"     => \"blog\",\n *         \"controller\" => \"index\",\n *     ]\n * );\n *\n * \/\/ All the routes start with \/blog\n * $blog->setPrefix(\"\/blog\");\n *\n * \/\/ Add a route to the group\n * $blog->add(\n *     \"\/save\",\n *     [\n *         \"action\" => \"save\",\n *     ]\n * );\n *\n * \/\/ Add another route to the group\n * $blog->add(\n *     \"\/edit\/{id}\",\n *     [\n *         \"action\" => \"edit\",\n *     ]\n * );\n *\n * \/\/ This route maps to a controller different than the default\n * $blog->add(\n *     \"\/blog\",\n *     [\n *         \"controller\" => \"about\",\n *         \"action\"     => \"index\",\n *     ]\n * );\n *\n * \/\/ Add the group to the router\n * $router->mount($blog);\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
        "line": 61,
        "char": 9
    },
    {
        "type": "interface",
        "name": "GroupInterface",
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 70,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 70,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 70,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 70,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 70,
                            "char": 82
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router on any HTTP method\n     *\n     *```php\n     * router->add(\"\/about\", \"About::index\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 70,
                                    "char": 103
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 70,
                                "char": 103
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 70,
                        "char": 103
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 70,
                    "last-line": 74,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 75,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 75,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 75,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 75,
                                    "char": 86
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 75,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 75,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 75,
                    "last-line": 79,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 80,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 80,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 80,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 80,
                                    "char": 85
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 80,
                                "char": 85
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 80,
                        "char": 85
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 80,
                    "last-line": 84,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 85,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 85,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 85,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 85,
                                    "char": 82
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 85,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 85,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 85,
                    "last-line": 89,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 90,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 90,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 90,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 90,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 90,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 90,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 90,
                    "last-line": 94,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 95,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 95,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 95,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 95,
                                    "char": 86
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 95,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 95,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 95,
                    "last-line": 99,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 100,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 100,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 100,
                            "char": 63
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 100,
                                    "char": 84
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 100,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 100,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 100,
                    "last-line": 104,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 105,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 105,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 105,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 105,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 105,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 105,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 105,
                    "last-line": 109,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 110,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 110,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 110,
                            "char": 63
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is PURGE\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 110,
                                    "char": 84
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 110,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 110,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 110,
                    "last-line": 114,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 115,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 115,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 115,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 115,
                                    "char": 82
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 115,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 115,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 115,
                    "last-line": 119,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 120,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 120,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 120,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 120,
                                    "char": 84
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 120,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 120,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 120,
                    "last-line": 126,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "beforeMatch",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "beforeMatch",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 127,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Sets a callback that is called if the route is matched.\n     * The developer can implement any arbitrary conditions here\n     * If the callback returns false the route is treated as not matched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "GroupInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 127,
                                    "char": 74
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 127,
                                "char": 74
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 127,
                        "char": 74
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 127,
                    "last-line": 131,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "docblock": "**\n     * Removes all the pre-defined routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 132,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 132,
                    "last-line": 136,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBeforeMatch",
                    "docblock": "**\n     * Returns the 'before match' callback if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "callable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 137,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 137,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 137,
                    "last-line": 141,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHostname",
                    "docblock": "**\n     * Returns the hostname restriction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 142,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 142,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 142,
                    "last-line": 146,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPaths",
                    "docblock": "**\n     * Returns the common paths defined for this group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 147,
                                "char": 41
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 147,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 147,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 147,
                    "last-line": 151,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrefix",
                    "docblock": "**\n     * Returns the common prefix for all the routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 152,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 152,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 152,
                    "last-line": 156,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRoutes",
                    "docblock": "**\n     * Returns the routes added to the group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 157,
                                    "char": 54
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 157,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 157,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 157,
                    "last-line": 161,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 162,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Set a hostname restriction for all the routes in the group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "GroupInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 162,
                                    "char": 69
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 162,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 162,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 162,
                    "last-line": 168,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPaths",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 169,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Set common paths for all the routes in the group\n     *\n     * @param array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "GroupInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 169,
                                    "char": 60
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 169,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 169,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 169,
                    "last-line": 173,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                            "line": 174,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Set a common uri prefix for all the routes in this group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "GroupInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                    "line": 174,
                                    "char": 65
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                                "line": 174,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                        "line": 174,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
                    "line": 174,
                    "last-line": 175,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
            "line": 175,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Router\/GroupInterface.zep",
        "line": 0,
        "char": 0
    }
]