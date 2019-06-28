[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\Route",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 15,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\RequestInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 16,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\GroupInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 17,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\RouteInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 18,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 19,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 20,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 21,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 50,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Router\n *\n * Phalcon\\Mvc\\Router is the standard framework router. Routing is the\n * process of taking a URI endpoint (that part of the URI which comes after the\n * base URL) and decomposing it into parameters to determine which module,\n * controller, and action of that controller should receive the request\n *\n * ```php\n * use Phalcon\\Mvc\\Router;\n *\n * $router = new Router();\n *\n * $router->add(\n *     \"\/documentation\/{chapter}\/{name}\\.{type:[a-z]+}\",\n *     [\n *         \"controller\" => \"documentation\",\n *         \"action\"     => \"show\",\n *     ]\n * );\n *\n * $router->handle(\n *     \"\/documentation\/1\/examples.html\"\n * );\n *\n * echo $router->getControllerName();\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 51,
        "char": 5
    },
    {
        "type": "class",
        "name": "Router",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 51,
                "char": 48
            },
            {
                "type": "variable",
                "value": "RouterInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 51,
                "char": 65
            },
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                "line": 52,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "action",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 56,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 57,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 58,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "controller",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 58,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 59,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultAction",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 60,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultController",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 61,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultModule",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 62,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultNamespace",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 63,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultParams",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 63,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 64,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 65,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "keyRouteNames",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 65,
                        "char": 34
                    },
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 65,
                            "char": 39
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 65,
                            "char": 45
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 66,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "keyRouteIds",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 66,
                        "char": 32
                    },
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 66,
                            "char": 37
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 66,
                            "char": 43
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 67,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "matchedRoute",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 68,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "matches",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 69,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "module",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 69,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 70,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "namespaceName",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 70,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 71,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "notFoundPaths",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 72,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "params",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 72,
                        "char": 26
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 73,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "removeExtraSlashes",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 74,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "routes",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 75,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "uriSource",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 76,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "wasMatched",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 76,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 80,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "defaultRoutes",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 81,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 81,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "routes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 83,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 83,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 85,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "defaultRoutes",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 85,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "routes",
                                            "expr": {
                                                "type": "new",
                                                "class": "Route",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "#^\/([\\\\w0-9\\\\_\\\\-]+)[\/]{0,1}$#u",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 92,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 92,
                                                        "char": 48
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "controller",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 94,
                                                                        "char": 31
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 95,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 95,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 96,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 96,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 96,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 96,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 98,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "routes",
                                            "expr": {
                                                "type": "new",
                                                "class": "Route",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "#^\/([\\\\w0-9\\\\_\\\\-]+)\/([\\\\w0-9\\\\.\\\\_]+)(\/.*)*$#u",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 99,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 99,
                                                        "char": 64
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "controller",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 101,
                                                                        "char": 31
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 101,
                                                                        "char": 34
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 101,
                                                                    "char": 34
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "action",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 102,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "2",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 102,
                                                                        "char": 34
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 102,
                                                                    "char": 34
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "params",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 103,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "3",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 104,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 104,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 105,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 105,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 105,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 105,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 106,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 108,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "routes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "routes",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 108,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 108,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 109,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Router constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 81,
                    "last-line": 132,
                    "char": 19
                },
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 133,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 133,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 133,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 133,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 133,
                            "char": 82
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 133,
                                    "char": 120
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 133,
                                    "char": 120
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 133,
                                "char": 120
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 133,
                            "char": 120
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 135,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 140,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "route",
                                    "expr": {
                                        "type": "new",
                                        "class": "Route",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pattern",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 140,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 140,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 140,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 140,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "httpMethods",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 140,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 140,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 140,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 140,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 142,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 142,
                                    "char": 14
                                },
                                "name": "attach",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "route",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 142,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 142,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 142,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 142,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 142,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 144,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "route",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 144,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 145,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router without any HTTP constraint\n     *\n     *```php\n     * use Phalcon\\Mvc\\Router;\n     *\n     * $router->add(\"\/about\", \"About::index\");\n     *\n     * $router->add(\n     *     \"\/about\",\n     *     \"About::index\",\n     *     [\"GET\", \"POST\"]\n     * );\n     *\n     * $router->add(\n     *     \"\/about\",\n     *     \"About::index\",\n     *     [\"GET\", \"POST\"],\n     *     Router::POSITION_FIRST\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 134,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 133,
                    "last-line": 149,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 150,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 150,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 150,
                            "char": 65
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 150,
                                    "char": 103
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 150,
                                    "char": 103
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 150,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 150,
                            "char": 103
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 152,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 152,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 152,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 152,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 152,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "CONNECT",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 152,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 152,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 152,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 152,
                                        "char": 59
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 152,
                                "char": 60
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 153,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 151,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 151,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 151,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 150,
                    "last-line": 157,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 158,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 158,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 158,
                            "char": 64
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 158,
                                    "char": 102
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 158,
                                    "char": 102
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 158,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 158,
                            "char": 102
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 160,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 160,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 160,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 160,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 160,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "DELETE",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 160,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 160,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 160,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 160,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 160,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 161,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 159,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 159,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 158,
                    "last-line": 165,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 166,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 166,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 166,
                            "char": 61
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 166,
                                    "char": 99
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 166,
                                    "char": 99
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 166,
                                "char": 99
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 166,
                            "char": 99
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 168,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 168,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 168,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 168,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 168,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "GET",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 168,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 168,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 168,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 168,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 168,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 169,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 167,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 167,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 167,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 166,
                    "last-line": 173,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 174,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 174,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 174,
                            "char": 62
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 174,
                                    "char": 100
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 174,
                                    "char": 100
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 174,
                                "char": 100
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 174,
                            "char": 100
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 176,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 176,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 176,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 176,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 176,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "HEAD",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 176,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 176,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 176,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 176,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 176,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 177,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 175,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 175,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 174,
                    "last-line": 181,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 182,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 182,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 182,
                            "char": 65
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 182,
                                    "char": 103
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 182,
                                    "char": 103
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 182,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 182,
                            "char": 103
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 184,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 184,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 184,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 184,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 184,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "OPTIONS",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 184,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 184,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 184,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 184,
                                        "char": 59
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 184,
                                "char": 60
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 185,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 183,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 183,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 183,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 182,
                    "last-line": 189,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 190,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 190,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 190,
                            "char": 63
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 190,
                                    "char": 101
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 190,
                                    "char": 101
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 190,
                                "char": 101
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 190,
                            "char": 101
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 192,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 192,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 192,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 192,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 192,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PATCH",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 192,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 192,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 192,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 192,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 192,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 193,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 191,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 191,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 191,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 190,
                    "last-line": 197,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 198,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 198,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 198,
                            "char": 62
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 198,
                                    "char": 100
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 198,
                                    "char": 100
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 198,
                                "char": 100
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 198,
                            "char": 100
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 200,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 200,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 200,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 200,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 200,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "POST",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 200,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 200,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 200,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 200,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 200,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 201,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 199,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 199,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 199,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 198,
                    "last-line": 206,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 207,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 207,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 207,
                            "char": 63
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 207,
                                    "char": 101
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 207,
                                    "char": 101
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 207,
                                "char": 101
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 207,
                            "char": 101
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 209,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 209,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 209,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 209,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 209,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PURGE",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 209,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 209,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 209,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 209,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 209,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 210,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 208,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 208,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 208,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 207,
                    "last-line": 214,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 215,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 215,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 215,
                            "char": 61
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 215,
                                    "char": 99
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 215,
                                    "char": 99
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 215,
                                "char": 99
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 215,
                            "char": 99
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 217,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 217,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 217,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 217,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 217,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PUT",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 217,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 217,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 217,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 217,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 217,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 218,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 216,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 216,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 216,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 215,
                    "last-line": 222,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 223,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 223,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 223,
                            "char": 63
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 223,
                                    "char": 101
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 223,
                                    "char": 101
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 223,
                                "char": 101
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 223,
                            "char": 101
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 225,
                                    "char": 21
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 225,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 225,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 225,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 225,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "TRACE",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 225,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 225,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 225,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 225,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 225,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 226,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 224,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 224,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 224,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 223,
                    "last-line": 246,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 247,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 247,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 247,
                                    "char": 88
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "POSITION_LAST",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 247,
                                    "char": 88
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 247,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 247,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "position",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 249,
                                "char": 25
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 250,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "POSITION_LAST",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 250,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 250,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-append",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "routes",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "route",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 251,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 251,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 252,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 253,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 253,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 253,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "POSITION_FIRST",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 253,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 253,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "routes",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array",
                                                                    "left": [
                                                                        {
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "route",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 254,
                                                                                "char": 54
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 254,
                                                                            "char": 54
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 254,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 254,
                                                                "char": 55
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 254,
                                                                        "char": 62
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "routes",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 254,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 254,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 254,
                                                                "char": 69
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 254,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 254,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 255,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 256,
                                            "char": 19
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 256,
                                    "char": 19
                                },
                                {
                                    "type": "default",
                                    "statements": [
                                        {
                                            "type": "throw",
                                            "expr": {
                                                "type": "new",
                                                "class": "Exception",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "Invalid route position",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 257,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 257,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 257,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 258,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 258,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 260,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 260,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 261,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Attach Route object to the routes stack.\n     *\n     * ```php\n     * use Phalcon\\Mvc\\Router;\n     * use Phalcon\\Mvc\\Router\\Route;\n     *\n     * class CustomRoute extends Route {\n     *      \/\/ ...\n     * }\n     *\n     * $router = new Router();\n     *\n     * $router->attach(\n     *     new CustomRoute(\"\/about\", \"About::index\", [\"GET\", \"HEAD\"]),\n     *     Router::POSITION_FIRST\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 248,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 248,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 248,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 247,
                    "last-line": 265,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "routes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 268,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 268,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 269,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes all the pre-defined routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 267,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 266,
                    "last-line": 273,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 276,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 276,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 276,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 277,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 275,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 275,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 275,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 274,
                    "last-line": 281,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEventsManager",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 284,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 284,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 284,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 285,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 283,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 283,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 283,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 282,
                    "last-line": 289,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 292,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "action",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 292,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 292,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 293,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the processed action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 291,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 291,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 290,
                    "last-line": 297,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getControllerName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 300,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "controller",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 300,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 300,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 301,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the processed controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 299,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 299,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 298,
                    "last-line": 305,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMatchedRoute",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 308,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "matchedRoute",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 308,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 308,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 309,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the route that matches the handled URI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 307,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 307,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 307,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 306,
                    "last-line": 313,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMatches",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 316,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "matches",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 316,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 316,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 317,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the sub expressions in the regular expression matched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 315,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 315,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 314,
                    "last-line": 321,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModuleName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 324,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "module",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 324,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 324,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 325,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the processed module name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 323,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 323,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 322,
                    "last-line": 329,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNamespaceName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 332,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "namespaceName",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 332,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 332,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 333,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the processed namespace name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 331,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 331,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 330,
                    "last-line": 337,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParams",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 340,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 340,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 340,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 341,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the processed parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 339,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 339,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 338,
                    "last-line": 345,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 346,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 348,
                                    "char": 18
                                },
                                {
                                    "variable": "routeId",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 348,
                                    "char": 27
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 348,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 350,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 350,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 350,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "keyRouteIds",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 350,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 350,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 350,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 350,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 350,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 351,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "routes",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 351,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 351,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 351,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 351,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 352,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 354,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 354,
                                    "char": 32
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 354,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 354,
                                "char": 40
                            },
                            "key": "key",
                            "value": "route",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "routeId",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 355,
                                                    "char": 33
                                                },
                                                "name": "getRouteId",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 355,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 355,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 356,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "keyRouteIds",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "routeId",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 356,
                                                    "char": 42
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 356,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 356,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 358,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "routeId",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 358,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 358,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 358,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "route",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 359,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 360,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 361,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 363,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 363,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 364,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 346,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 346,
                                "char": 62
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 347,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 347,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 346,
                    "last-line": 368,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 369,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 371,
                                    "char": 18
                                },
                                {
                                    "variable": "routeName",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 371,
                                    "char": 29
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 371,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 373,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 373,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 373,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "keyRouteNames",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 373,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 373,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 373,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 373,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 373,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 374,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "routes",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 374,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 374,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 374,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 374,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 375,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 377,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 377,
                                    "char": 32
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 377,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 377,
                                "char": 40
                            },
                            "key": "key",
                            "value": "route",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "routeName",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 378,
                                                    "char": 35
                                                },
                                                "name": "getName",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 378,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 378,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 380,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "routeName",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 380,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 380,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 380,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "keyRouteNames",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "routeName",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 381,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 381,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 381,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 383,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "routeName",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 383,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 383,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 383,
                                                "char": 38
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "route",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 384,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 385,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 386,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 387,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 389,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 389,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 390,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 369,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 369,
                                "char": 70
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 370,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 370,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 369,
                    "last-line": 394,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRoutes",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 397,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 397,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 397,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 398,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns all the routes defined in the router\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 396,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 396,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 396,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 395,
                    "last-line": 407,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 408,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "request",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 410,
                                    "char": 20
                                },
                                {
                                    "variable": "currentHostName",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 410,
                                    "char": 37
                                },
                                {
                                    "variable": "routeFound",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 410,
                                    "char": 49
                                },
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 410,
                                    "char": 56
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 410,
                                    "char": 64
                                },
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 410,
                                    "char": 73
                                },
                                {
                                    "variable": "notFoundPaths",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 411,
                                    "char": 26
                                },
                                {
                                    "variable": "vnamespace",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 411,
                                    "char": 38
                                },
                                {
                                    "variable": "module",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 411,
                                    "char": 46
                                },
                                {
                                    "variable": "controller",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 411,
                                    "char": 59
                                },
                                {
                                    "variable": "action",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 411,
                                    "char": 67
                                },
                                {
                                    "variable": "paramsStr",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 411,
                                    "char": 78
                                },
                                {
                                    "variable": "strParams",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 412,
                                    "char": 22
                                },
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 412,
                                    "char": 29
                                },
                                {
                                    "variable": "methods",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 412,
                                    "char": 38
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 412,
                                    "char": 49
                                },
                                {
                                    "variable": "hostname",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 412,
                                    "char": 59
                                },
                                {
                                    "variable": "regexHostName",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 412,
                                    "char": 74
                                },
                                {
                                    "variable": "matched",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 413,
                                    "char": 20
                                },
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 413,
                                    "char": 29
                                },
                                {
                                    "variable": "handledUri",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 413,
                                    "char": 41
                                },
                                {
                                    "variable": "beforeMatch",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 413,
                                    "char": 54
                                },
                                {
                                    "variable": "paths",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 413,
                                    "char": 61
                                },
                                {
                                    "variable": "converters",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 413,
                                    "char": 73
                                },
                                {
                                    "variable": "part",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 413,
                                    "char": 79
                                },
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 414,
                                    "char": 21
                                },
                                {
                                    "variable": "matchPosition",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 414,
                                    "char": 36
                                },
                                {
                                    "variable": "converter",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 414,
                                    "char": 47
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 414,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 416,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uri",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "parse_url",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 416,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 416,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "PHP_URL_PATH",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 416,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 416,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 416,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 416,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 421,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 421,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "removeExtraSlashes",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 421,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 421,
                                    "char": 38
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "uri",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 421,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "\/",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 421,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 421,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 421,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handledUri",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "rtrim",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "uri",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 422,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 422,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\/",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 422,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 422,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 422,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 422,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 423,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handledUri",
                                            "expr": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 424,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 424,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 425,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 427,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "request",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 427,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 427,
                                    "char": 27
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "currentHostName",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 428,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 428,
                                    "char": 35
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "routeFound",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 429,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 429,
                                    "char": 31
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "parts",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 430,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 430,
                                    "char": 23
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 431,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 431,
                                    "char": 24
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "matches",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 432,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 432,
                                    "char": 27
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "wasMatched",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 433,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 433,
                                    "char": 37
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "matchedRoute",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 434,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 434,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 436,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 436,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 436,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 436,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 436,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 438,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 438,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 438,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 438,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 438,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 439,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "router:beforeCheckRoutes",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 439,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 439,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 439,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 439,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 439,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 440,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 445,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 445,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 445,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 445,
                                "char": 43
                            },
                            "value": "route",
                            "reverse": 1,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 446,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 446,
                                            "char": 28
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "matches",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 447,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 447,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 452,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "methods",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 452,
                                                    "char": 33
                                                },
                                                "name": "getHttpMethods",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 452,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 452,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 454,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "methods",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 454,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 454,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 454,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "request",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 458,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 458,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 458,
                                                "char": 37
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "container",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "DiInterface",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 459,
                                                                    "char": 66
                                                                },
                                                                "right": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 459,
                                                                        "char": 56
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 459,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 459,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 459,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 459,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 461,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "not-equals",
                                                            "left": {
                                                                "type": "typeof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "container",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 461,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 461,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "object",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 461,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 461,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 461,
                                                        "char": 60
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Exception",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "scall",
                                                                            "dynamic-class": 0,
                                                                            "class": "Exception",
                                                                            "dynamic": 0,
                                                                            "name": "containerServiceNotFound",
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "the 'request' service",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 465,
                                                                                        "char": 29
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 465,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 466,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 466,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 466,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 467,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 469,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "request",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "RequestInterface",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 469,
                                                                    "char": 83
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 469,
                                                                        "char": 64
                                                                    },
                                                                    "name": "getShared",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "request",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 469,
                                                                                "char": 82
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 469,
                                                                            "char": 82
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 469,
                                                                    "char": 83
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 469,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 469,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 470,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 475,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "request",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 475,
                                                        "char": 28
                                                    },
                                                    "name": "isMethod",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "methods",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 475,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 475,
                                                            "char": 45
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 475,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 475,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 475,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 475,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 475,
                                                "char": 63
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 477,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 478,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 483,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hostname",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 483,
                                                    "char": 34
                                                },
                                                "name": "getHostName",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 483,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 483,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 485,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "hostname",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 485,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 485,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 485,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "request",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 489,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 489,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 489,
                                                "char": 37
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "container",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "DiInterface",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 490,
                                                                    "char": 66
                                                                },
                                                                "right": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 490,
                                                                        "char": 56
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 490,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 490,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 490,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 490,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 492,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "not-equals",
                                                            "left": {
                                                                "type": "typeof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "container",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 492,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 492,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "object",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 492,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 492,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 492,
                                                        "char": 60
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Exception",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "scall",
                                                                            "dynamic-class": 0,
                                                                            "class": "Exception",
                                                                            "dynamic": 0,
                                                                            "name": "containerServiceNotFound",
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "the 'request' service",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 496,
                                                                                        "char": 29
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 496,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 497,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 497,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 497,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 498,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 500,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "request",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "RequestInterface",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 500,
                                                                    "char": 83
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 500,
                                                                        "char": 64
                                                                    },
                                                                    "name": "getShared",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "request",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 500,
                                                                                "char": 82
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 500,
                                                                            "char": 82
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 500,
                                                                    "char": 83
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 500,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 500,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 501,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 506,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "currentHostName",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 506,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 506,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 506,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "currentHostName",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "request",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 507,
                                                                    "char": 51
                                                                },
                                                                "name": "getHttpHost",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 507,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 507,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 508,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 513,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "currentHostName",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 513,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 513,
                                                "char": 37
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 515,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 521,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "hostname",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 521,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 521,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "(",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 521,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 521,
                                                        "char": 38
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 521,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "memstr",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "hostname",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 522,
                                                                        "char": 40
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 522,
                                                                    "char": 40
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "#",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 522,
                                                                        "char": 43
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 522,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 522,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 522,
                                                        "char": 45
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "regexHostName",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "#^",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 523,
                                                                            "char": 48
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "hostname",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 523,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 523,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 523,
                                                                    "char": 58
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 525,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "not",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "memstr",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "hostname",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 525,
                                                                                "char": 44
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 525,
                                                                            "char": 44
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": ":",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 525,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 525,
                                                                            "char": 47
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 525,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 525,
                                                                "char": 49
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "concat-assign",
                                                                            "variable": "regexHostName",
                                                                            "expr": {
                                                                                "type": "string",
                                                                                "value": "(:[[:digit:]]+)?",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 526,
                                                                                "char": 65
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 526,
                                                                            "char": 65
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 527,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 529,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "regexHostName",
                                                                    "expr": {
                                                                        "type": "string",
                                                                        "value": "$#i",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 529,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 529,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 530,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "regexHostName",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "hostname",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 531,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 531,
                                                                    "char": 53
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 532,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 534,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "matched",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "preg_match",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "regexHostName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 534,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 534,
                                                                        "char": 59
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "currentHostName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 534,
                                                                            "char": 76
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 534,
                                                                        "char": 76
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 534,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 534,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 535,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "matched",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "currentHostName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 536,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "hostname",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 536,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 536,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 536,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 537,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 539,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "matched",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 539,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 539,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 541,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 542,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 544,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 544,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 544,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 544,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 544,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 545,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "router:beforeCheckRoute",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 545,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 545,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 545,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 545,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "route",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 545,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 545,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 545,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 546,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 551,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "pattern",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 551,
                                                    "char": 33
                                                },
                                                "name": "getCompiledPattern",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 551,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 551,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 553,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "memstr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pattern",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 553,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 553,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "^",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 553,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 553,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 553,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "routeFound",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "preg_match",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 554,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 554,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "handledUri",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 554,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 554,
                                                                "char": 64
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "matches",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 554,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 554,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 554,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 554,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 555,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "routeFound",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "pattern",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 556,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "handledUri",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 556,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 556,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 556,
                                                    "char": 55
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 557,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 562,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "routeFound",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 562,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "eventsManager",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 563,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 563,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 563,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 563,
                                                "char": 51
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "eventsManager",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 564,
                                                            "char": 35
                                                        },
                                                        "name": "fire",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "router:matchedRoute",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 564,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 564,
                                                                "char": 60
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 564,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 564,
                                                                "char": 66
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "route",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 564,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 564,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 564,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 565,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 567,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "beforeMatch",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "route",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 567,
                                                            "char": 41
                                                        },
                                                        "name": "getBeforeMatch",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 567,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 567,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 569,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "beforeMatch",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 569,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 569,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 569,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "fcall",
                                                                "name": "is_callable",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "beforeMatch",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 573,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 573,
                                                                        "char": 57
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 573,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 573,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 573,
                                                        "char": 59
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Exception",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "Before-Match callback is not callable in matched route",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 576,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 576,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 576,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 577,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 582,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "routeFound",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "call_user_func_array",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "beforeMatch",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 583,
                                                                            "char": 36
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 583,
                                                                        "char": 36
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "handledUri",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 585,
                                                                                        "char": 39
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 585,
                                                                                    "char": 39
                                                                                },
                                                                                {
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "route",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 586,
                                                                                        "char": 34
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 586,
                                                                                    "char": 34
                                                                                },
                                                                                {
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 588,
                                                                                        "char": 25
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 588,
                                                                                    "char": 25
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 589,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 589,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 589,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 589,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 590,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 592,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "eventsManager",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 593,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 593,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 593,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 593,
                                                "char": 51
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "routeFound",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "eventsManager",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 594,
                                                                    "char": 52
                                                                },
                                                                "name": "fire",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "router:notMatchedRoute",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 594,
                                                                            "char": 80
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 594,
                                                                        "char": 80
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 594,
                                                                            "char": 86
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 594,
                                                                        "char": 86
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "route",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 594,
                                                                            "char": 93
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 594,
                                                                        "char": 93
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 594,
                                                                "char": 94
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 594,
                                                            "char": 94
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 595,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 596,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 598,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "routeFound",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 598,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "paths",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "route",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 602,
                                                            "char": 35
                                                        },
                                                        "name": "getPaths",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 602,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 602,
                                                    "char": 46
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "parts",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "paths",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 603,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 603,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 608,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "matches",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 608,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 608,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 608,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 608,
                                                "char": 44
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "converters",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "route",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 612,
                                                                    "char": 44
                                                                },
                                                                "name": "getConverters",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 612,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 612,
                                                            "char": 60
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 614,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "paths",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 614,
                                                        "char": 49
                                                    },
                                                    "key": "part",
                                                    "value": "position",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "unlikely",
                                                                "left": {
                                                                    "type": "not-equals",
                                                                    "left": {
                                                                        "type": "typeof",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "part",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 615,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 615,
                                                                        "char": 50
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "string",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 615,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 615,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 615,
                                                                "char": 59
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "throw",
                                                                    "expr": {
                                                                        "type": "new",
                                                                        "class": "Exception",
                                                                        "dynamic": 0,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "string",
                                                                                        "value": "Wrong key in paths: ",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 616,
                                                                                        "char": 70
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "part",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 616,
                                                                                        "char": 76
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 616,
                                                                                    "char": 76
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 616,
                                                                                "char": 76
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 616,
                                                                        "char": 77
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 617,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 619,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "and",
                                                                "left": {
                                                                    "type": "not-equals",
                                                                    "left": {
                                                                        "type": "typeof",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "position",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 619,
                                                                            "char": 45
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 619,
                                                                        "char": 45
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "string",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 619,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 619,
                                                                    "char": 55
                                                                },
                                                                "right": {
                                                                    "type": "not-equals",
                                                                    "left": {
                                                                        "type": "typeof",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "position",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 619,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 619,
                                                                        "char": 74
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "integer",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 619,
                                                                        "char": 84
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 619,
                                                                    "char": 84
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 619,
                                                                "char": 84
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 621,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 623,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "fetch",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "matchPosition",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 623,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "matches",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 623,
                                                                        "char": 56
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "position",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 623,
                                                                        "char": 65
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 623,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 623,
                                                                "char": 67
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "equals",
                                                                        "left": {
                                                                            "type": "typeof",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "converters",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 627,
                                                                                "char": 51
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 627,
                                                                            "char": 51
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "array",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 627,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 627,
                                                                        "char": 59
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "fetch",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "converter",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 628,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "converters",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 628,
                                                                                        "char": 63
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "part",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 628,
                                                                                        "char": 68
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 628,
                                                                                    "char": 70
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 628,
                                                                                "char": 70
                                                                            },
                                                                            "statements": [
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "array-index",
                                                                                            "operator": "assign",
                                                                                            "variable": "parts",
                                                                                            "index-expr": [
                                                                                                {
                                                                                                    "type": "variable",
                                                                                                    "value": "part",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                    "line": 629,
                                                                                                    "char": 51
                                                                                                }
                                                                                            ],
                                                                                            "expr": {
                                                                                                "type": "fcall",
                                                                                                "name": "call_user_func_array",
                                                                                                "call-type": 1,
                                                                                                "parameters": [
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "variable",
                                                                                                            "value": "converter",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                            "line": 630,
                                                                                                            "char": 50
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                        "line": 630,
                                                                                                        "char": 50
                                                                                                    },
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "array",
                                                                                                            "left": [
                                                                                                                {
                                                                                                                    "value": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "matchPosition",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                                        "line": 631,
                                                                                                                        "char": 55
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                                    "line": 631,
                                                                                                                    "char": 55
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                            "line": 632,
                                                                                                            "char": 37
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                        "line": 632,
                                                                                                        "char": 37
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                "line": 632,
                                                                                                "char": 38
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                            "line": 632,
                                                                                            "char": 38
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 634,
                                                                                    "char": 44
                                                                                },
                                                                                {
                                                                                    "type": "continue",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 635,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 636,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 641,
                                                                    "char": 31
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "array-index",
                                                                            "operator": "assign",
                                                                            "variable": "parts",
                                                                            "index-expr": [
                                                                                {
                                                                                    "type": "variable",
                                                                                    "value": "part",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 641,
                                                                                    "char": 43
                                                                                }
                                                                            ],
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "matchPosition",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 641,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 641,
                                                                            "char": 60
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 642,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "equals",
                                                                        "left": {
                                                                            "type": "typeof",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "converters",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 646,
                                                                                "char": 51
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 646,
                                                                            "char": 51
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "array",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 646,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 646,
                                                                        "char": 59
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "fetch",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "converter",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 647,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "converters",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 647,
                                                                                        "char": 63
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "part",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 647,
                                                                                        "char": 68
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 647,
                                                                                    "char": 70
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 647,
                                                                                "char": 70
                                                                            },
                                                                            "statements": [
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "array-index",
                                                                                            "operator": "assign",
                                                                                            "variable": "parts",
                                                                                            "index-expr": [
                                                                                                {
                                                                                                    "type": "variable",
                                                                                                    "value": "part",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                    "line": 648,
                                                                                                    "char": 51
                                                                                                }
                                                                                            ],
                                                                                            "expr": {
                                                                                                "type": "fcall",
                                                                                                "name": "call_user_func_array",
                                                                                                "call-type": 1,
                                                                                                "parameters": [
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "variable",
                                                                                                            "value": "converter",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                            "line": 649,
                                                                                                            "char": 50
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                        "line": 649,
                                                                                                        "char": 50
                                                                                                    },
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "array",
                                                                                                            "left": [
                                                                                                                {
                                                                                                                    "value": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "position",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                                        "line": 650,
                                                                                                                        "char": 50
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                                    "line": 650,
                                                                                                                    "char": 50
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                            "line": 651,
                                                                                                            "char": 37
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                        "line": 651,
                                                                                                        "char": 37
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                                "line": 651,
                                                                                                "char": 38
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                            "line": 651,
                                                                                            "char": 38
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 652,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 653,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "else_statements": [
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "equals",
                                                                                "left": {
                                                                                    "type": "typeof",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "position",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 658,
                                                                                        "char": 53
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 658,
                                                                                    "char": 53
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "integer",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 658,
                                                                                    "char": 63
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 658,
                                                                                "char": 63
                                                                            },
                                                                            "statements": [
                                                                                {
                                                                                    "type": "unset",
                                                                                    "expr": {
                                                                                        "type": "array-access",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "parts",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                            "line": 659,
                                                                                            "char": 48
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "part",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                            "line": 659,
                                                                                            "char": 53
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                        "line": 659,
                                                                                        "char": 54
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 660,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 661,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 662,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 663,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 668,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "matches",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "matches",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 668,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 668,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 669,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 671,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "matchedRoute",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "route",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 671,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 671,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 673,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 674,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 675,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 680,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "routeFound",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 680,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "wasMatched",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 681,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 681,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 682,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "wasMatched",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 683,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 683,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 684,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 689,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "routeFound",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 689,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 689,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "notFoundPaths",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 690,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "notFoundPaths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 690,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 690,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 690,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 692,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "notFoundPaths",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 692,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 692,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 692,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "parts",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Route",
                                                        "dynamic": 0,
                                                        "name": "getRoutePaths",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "notFoundPaths",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 693,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 693,
                                                                "char": 63
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 693,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 693,
                                                    "char": 64
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "routeFound",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 694,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 694,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 695,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 696,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 701,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "namespaceName",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 701,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "defaultNamespace",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 701,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 701,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 701,
                                    "char": 57
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "module",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 702,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "defaultModule",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 702,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 702,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 702,
                                    "char": 47
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "controller",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 703,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "defaultController",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 703,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 703,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 703,
                                    "char": 55
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "action",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 704,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "defaultAction",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 704,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 704,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 704,
                                    "char": 47
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "params",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 705,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "defaultParams",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 705,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 705,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 705,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 707,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "routeFound",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 707,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "vnamespace",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 711,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "parts",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 711,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "namespace",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 711,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 711,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 711,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "is_numeric",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "vnamespace",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 712,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 712,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 712,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 712,
                                                "char": 44
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "namespaceName",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "vnamespace",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 713,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 713,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 714,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 716,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "parts",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 716,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "namespace",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 716,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 716,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 717,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 722,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "module",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 722,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "parts",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 722,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "module",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 722,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 722,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 722,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "is_numeric",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "module",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 723,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 723,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 723,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 723,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "module",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "module",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 724,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 724,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 725,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 727,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "parts",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 727,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "module",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 727,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 727,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 728,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 733,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "controller",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 733,
                                            "char": 52
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "parts",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 733,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "controller",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 733,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 733,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 733,
                                        "char": 52
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "is_numeric",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "controller",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 734,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 734,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 734,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 734,
                                                "char": 44
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "controller",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "controller",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 735,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 735,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 736,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 738,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "parts",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 738,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "controller",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 738,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 738,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 739,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 744,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "action",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 744,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "parts",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 744,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "action",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 744,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 744,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 744,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "is_numeric",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "action",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 745,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 745,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 745,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 745,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "action",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "action",
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 746,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 746,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 747,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 749,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "parts",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 749,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 749,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 749,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 750,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 755,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "paramsStr",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 755,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "parts",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 755,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 755,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 755,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 755,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "paramsStr",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 756,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 756,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 756,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 756,
                                                "char": 47
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "strParams",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "trim",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "paramsStr",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 757,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 757,
                                                                        "char": 51
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "\/",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                            "line": 757,
                                                                            "char": 54
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 757,
                                                                        "char": 54
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 757,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 757,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 759,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not-identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "strParams",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 759,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 759,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 759,
                                                        "char": 39
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "params",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "explode",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "\/",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 760,
                                                                                    "char": 47
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 760,
                                                                                "char": 47
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "strParams",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                    "line": 760,
                                                                                    "char": 58
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                                "line": 760,
                                                                                "char": 58
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                        "line": 760,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 760,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 761,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 762,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 764,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "parts",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 764,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 764,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 764,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 765,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 767,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 767,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 767,
                                                "char": 28
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 767,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "params",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "params",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 768,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 768,
                                                                "char": 54
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                    "line": 768,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                                "line": 768,
                                                                "char": 61
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 768,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 768,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 769,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "params",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "parts",
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 770,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 770,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 771,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 772,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 774,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 774,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 774,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 774,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 774,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 775,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "router:afterCheckRoutes",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 775,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 775,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 775,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 775,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 775,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 776,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 777,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Handles routing information received from the rewrite engine\n     *\n     *```php\n     * \/\/ Passing a URL\n     * $router->handle(\"\/posts\/edit\/1\");\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 408,
                    "last-line": 781,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isExactControllerName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 784,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 785,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns whether controller name should not be mangled\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 783,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 783,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 782,
                    "last-line": 789,
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
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 790,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 790,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "groupRoutes",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 792,
                                    "char": 24
                                },
                                {
                                    "variable": "beforeMatch",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 792,
                                    "char": 37
                                },
                                {
                                    "variable": "hostname",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 792,
                                    "char": 47
                                },
                                {
                                    "variable": "routes",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 792,
                                    "char": 55
                                },
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 792,
                                    "char": 62
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 792,
                                    "char": 77
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 794,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 794,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 794,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 794,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 794,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 796,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 796,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 796,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 796,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 796,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 797,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "router:beforeMount",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 797,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 797,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 797,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 797,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "group",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 797,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 797,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 797,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 798,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 800,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "groupRoutes",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "group",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 800,
                                            "char": 33
                                        },
                                        "name": "getRoutes",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 800,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 800,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 802,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "groupRoutes",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 802,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 802,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 802,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 802,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 802,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The group of routes does not contain any routes",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 805,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 805,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 805,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 806,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 811,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "beforeMatch",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "group",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 811,
                                            "char": 33
                                        },
                                        "name": "getBeforeMatch",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 811,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 811,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 813,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "beforeMatch",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 813,
                                    "char": 26
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 813,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 813,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "groupRoutes",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 814,
                                        "char": 38
                                    },
                                    "value": "route",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 815,
                                                    "char": 23
                                                },
                                                "name": "beforeMatch",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "beforeMatch",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 815,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 815,
                                                        "char": 47
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 815,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 816,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 817,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 820,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hostname",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "group",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 820,
                                            "char": 30
                                        },
                                        "name": "getHostName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 820,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 820,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 822,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "hostname",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 822,
                                    "char": 23
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 822,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 822,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "groupRoutes",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 823,
                                        "char": 38
                                    },
                                    "value": "route",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 824,
                                                    "char": 23
                                                },
                                                "name": "setHostName",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "hostname",
                                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                            "line": 824,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                        "line": 824,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 824,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 825,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 826,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 828,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "routes",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 828,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "routes",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 828,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 828,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 828,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 830,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "routes",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "routes",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 830,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 830,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "groupRoutes",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 830,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 830,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 830,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 830,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 832,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 832,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 833,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 791,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 791,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 791,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 790,
                    "last-line": 838,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notFound",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 839,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 841,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 841,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 841,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 841,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 841,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 841,
                                                "char": 61
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 841,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 841,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 841,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 841,
                                    "char": 71
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 841,
                                "char": 71
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The not-found paths must be an array or string",
                                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                    "line": 844,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 844,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 844,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 845,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 847,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "notFoundPaths",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paths",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 847,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 847,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 849,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 849,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 850,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set a group of paths to be returned when none of the defined routes are\n     * matched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 840,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 840,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 840,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 839,
                    "last-line": 854,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "removeExtraSlashes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "remove",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 855,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "removeExtraSlashes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "remove",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 857,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 857,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 859,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 859,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 860,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set whether router must remove the extra slashes in the handled routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 856,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 856,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 856,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 855,
                    "last-line": 864,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 865,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "defaultAction",
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionName",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 867,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 867,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 869,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 869,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 870,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 866,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 866,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 866,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 865,
                    "last-line": 874,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 875,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "defaultController",
                                    "expr": {
                                        "type": "variable",
                                        "value": "controllerName",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 877,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 877,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 879,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 879,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 880,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 876,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 876,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 876,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 875,
                    "last-line": 884,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 885,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "defaultModule",
                                    "expr": {
                                        "type": "variable",
                                        "value": "moduleName",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 887,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 887,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 889,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 889,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 890,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the name of the default module\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 886,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 886,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 886,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 885,
                    "last-line": 894,
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
                            "name": "namespaceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 895,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "defaultNamespace",
                                    "expr": {
                                        "type": "variable",
                                        "value": "namespaceName",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 897,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 897,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 899,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 899,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 900,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the name of the default namespace\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 896,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 896,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 896,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 895,
                    "last-line": 915,
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
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 916,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "namespaceName",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 918,
                                    "char": 26
                                },
                                {
                                    "variable": "module",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 918,
                                    "char": 34
                                },
                                {
                                    "variable": "controller",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 918,
                                    "char": 46
                                },
                                {
                                    "variable": "action",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 918,
                                    "char": 54
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 918,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 921,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "namespaceName",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 921,
                                    "char": 53
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 921,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "namespace",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 921,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 921,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 921,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "defaultNamespace",
                                            "expr": {
                                                "type": "variable",
                                                "value": "namespaceName",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 922,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 922,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 923,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 926,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "module",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 926,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 926,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "module",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 926,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 926,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 926,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "defaultModule",
                                            "expr": {
                                                "type": "variable",
                                                "value": "module",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 927,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 927,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 928,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 931,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "controller",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 931,
                                    "char": 51
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 931,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "controller",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 931,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 931,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 931,
                                "char": 51
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "defaultController",
                                            "expr": {
                                                "type": "variable",
                                                "value": "controller",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 932,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 932,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 933,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 936,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "action",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 936,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 936,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "action",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 936,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 936,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 936,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "defaultAction",
                                            "expr": {
                                                "type": "variable",
                                                "value": "action",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 937,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 937,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 938,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 941,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 941,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 941,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 941,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 941,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 941,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "defaultParams",
                                            "expr": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 942,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 942,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 943,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 945,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 945,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 946,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an array of default paths. If a route is missing a path the router\n     * will use the defined here. This method must not be used to set a 404\n     * route\n     *\n     *```php\n     * $router->setDefaults(\n     *     [\n     *         \"module\" => \"common\",\n     *         \"action\" => \"index\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 917,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 917,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 917,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 916,
                    "last-line": 950,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaults",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "namespace",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 954,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 954,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultNamespace",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 954,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 954,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 954,
                                        "char": 47
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "module",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 955,
                                            "char": 19
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 955,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultModule",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 955,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 955,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 955,
                                        "char": 44
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "controller",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 956,
                                            "char": 23
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 956,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultController",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 956,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 956,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 956,
                                        "char": 48
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "action",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 957,
                                            "char": 19
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 957,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultAction",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 957,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 957,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 957,
                                        "char": 44
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 958,
                                            "char": 19
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 958,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultParams",
                                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                                "line": 959,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                            "line": 959,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 959,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 959,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 960,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of default parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 952,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 952,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 951,
                    "last-line": 964,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDI",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 965,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 965,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 967,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 967,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 968,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 966,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 965,
                    "last-line": 972,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEventsManager",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventsManager",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ManagerInterface",
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 973,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 973,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "eventsManager",
                                    "expr": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                        "line": 975,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 975,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 976,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 974,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 973,
                    "last-line": 980,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "wasMatched",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 983,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "wasMatched",
                                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                    "line": 983,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 983,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router.zep",
                            "line": 984,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if the router matches any of the defined routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router.zep",
                                "line": 982,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 982,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 981,
                    "last-line": 985,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "POSITION_FIRST",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 53,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 54,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "POSITION_LAST",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Router.zep",
                        "line": 54,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router.zep",
                    "line": 56,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Router.zep",
            "line": 51,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Router.zep",
        "line": 51,
        "char": 5
    }
]