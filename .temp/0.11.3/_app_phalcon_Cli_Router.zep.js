[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cli",
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Cli\/Router.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Cli\/Router.zep",
                "line": 14,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cli\\Router\\Route",
                "file": "\/app\/phalcon\/Cli\/Router.zep",
                "line": 15,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cli\\Router\\Exception",
                "file": "\/app\/phalcon\/Cli\/Router.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 37,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Cli\\Router is the standard framework router. Routing is the process\n * of taking a command-line arguments and decomposing it into parameters to\n * determine which module, task, and action of that task should receive the\n * request.\n *\n *```php\n * $router = new \\Phalcon\\Cli\\Router();\n *\n * $router->handle(\n *     [\n *         \"module\" => \"main\",\n *         \"task\"   => \"videos\",\n *         \"action\" => \"process\",\n *     ]\n * );\n *\n * echo $router->getTaskName();\n *```\n *",
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 38,
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
                "file": "\/app\/phalcon\/Cli\/Router.zep",
                "line": 39,
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
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 42,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 44,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultAction",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 44,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 46,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultModule",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 46,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultParams",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 51,
                        "char": 33
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 53,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultTask",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 53,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 55,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "matchedRoute",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 57,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "matches",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 59,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "module",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 63,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "params",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 64,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 66,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "routes",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 68,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "task",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 70,
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
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 70,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 74,
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
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 75,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 75,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "routes",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 77,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 79,
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
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 79,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 79,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 81,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "defaultRoutes",
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 81,
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
                                                            "value": "#^(?::delimiter)?([a-zA-Z0-9\\\\_\\\\-]+)[:delimiter]{0,1}$#",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 86,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 86,
                                                        "char": 73
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "task",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 88,
                                                                        "char": 25
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 89,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 89,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 90,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 90,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 90,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 90,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 92,
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
                                                            "value": "#^(?::delimiter)?([a-zA-Z0-9\\\\_\\\\-]+):delimiter([a-zA-Z0-9\\\\.\\\\_]+)(:delimiter.*)*$#",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 93,
                                                            "char": 101
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 93,
                                                        "char": 101
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "task",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 95,
                                                                        "char": 25
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 95,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 95,
                                                                    "char": 30
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "action",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 96,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "2",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 96,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 96,
                                                                    "char": 30
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "params",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 97,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "3",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 98,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 98,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 99,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 99,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 99,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 99,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 100,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 102,
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
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 102,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 102,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Cli\\Router constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 76,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 75,
                    "last-line": 113,
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
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 114,
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
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 114,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 114,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 116,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 118,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 118,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 118,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 118,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 118,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 118,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 118,
                                    "char": 46
                                },
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "routes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "route",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 119,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 119,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 121,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "route",
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 121,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 122,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router\n     *\n     *```php\n     * $router->add(\"\/about\", \"About::main\");\n     *```\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 115,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 115,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 115,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 114,
                    "last-line": 126,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 129,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "action",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 129,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 129,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 130,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns processed action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 128,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 128,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 127,
                    "last-line": 134,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 137,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 137,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 137,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 138,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 136,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 136,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 136,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 135,
                    "last-line": 142,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 145,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "matchedRoute",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 145,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 145,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 146,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 144,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 144,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 144,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 143,
                    "last-line": 150,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 153,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "matches",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 153,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 153,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 154,
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
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 152,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 152,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 151,
                    "last-line": 158,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 161,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "module",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 161,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 161,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 162,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns processed module name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 160,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 160,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 159,
                    "last-line": 166,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 169,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 169,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 169,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 170,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns processed extra params\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 168,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 168,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 167,
                    "last-line": 176,
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
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 177,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 179,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 181,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 181,
                                    "char": 27
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 181,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 181,
                                "char": 35
                            },
                            "value": "route",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "route",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 182,
                                                "char": 22
                                            },
                                            "name": "getRouteId",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 182,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 182,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 182,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "route",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 183,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 184,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 185,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 187,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 187,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 188,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a route object by its id\n     *\n     * @param int id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 177,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 177,
                                "char": 62
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 178,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 178,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 177,
                    "last-line": 192,
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
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 193,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 195,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 197,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 197,
                                    "char": 27
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 197,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 197,
                                "char": 35
                            },
                            "value": "route",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "route",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 198,
                                                "char": 22
                                            },
                                            "name": "getName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 198,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 198,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 198,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "route",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 199,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 200,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 201,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 203,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 203,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 204,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 193,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 193,
                                "char": 70
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 194,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 194,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 193,
                    "last-line": 208,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 211,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 211,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 211,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 212,
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
                                    "value": "Route",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 210,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 210,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 210,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 209,
                    "last-line": 216,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTaskName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 219,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "task",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 219,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 219,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 220,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns processed task name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 218,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 218,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 217,
                    "last-line": 226,
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
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 227,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 227,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "moduleName",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 229,
                                    "char": 23
                                },
                                {
                                    "variable": "taskName",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 229,
                                    "char": 33
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 229,
                                    "char": 45
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 229,
                                    "char": 53
                                },
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 229,
                                    "char": 60
                                },
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 229,
                                    "char": 67
                                },
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 229,
                                    "char": 76
                                },
                                {
                                    "variable": "routeFound",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 230,
                                    "char": 23
                                },
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 230,
                                    "char": 32
                                },
                                {
                                    "variable": "paths",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 230,
                                    "char": 39
                                },
                                {
                                    "variable": "beforeMatch",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 230,
                                    "char": 52
                                },
                                {
                                    "variable": "converters",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 230,
                                    "char": 64
                                },
                                {
                                    "variable": "converter",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 230,
                                    "char": 75
                                },
                                {
                                    "variable": "part",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 231,
                                    "char": 17
                                },
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 231,
                                    "char": 27
                                },
                                {
                                    "variable": "matchPosition",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 231,
                                    "char": 42
                                },
                                {
                                    "variable": "strParams",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 231,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 233,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "routeFound",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 233,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 233,
                                    "char": 31
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "parts",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 234,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 234,
                                    "char": 23
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 235,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 235,
                                    "char": 24
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "matches",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 236,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 236,
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
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 237,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 237,
                                    "char": 37
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "matchedRoute",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 238,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 238,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 240,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "arguments",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 240,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 240,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 240,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 240,
                                "char": 38
                            },
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
                                                            "value": "arguments",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 241,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 241,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 241,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 241,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "not-identical",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "arguments",
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 241,
                                                        "char": 68
                                                    },
                                                    "right": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 241,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 241,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 241,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 241,
                                            "char": 76
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 241,
                                        "char": 76
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
                                                            "value": "Arguments must be an array or string",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 242,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 242,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 242,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 243,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 245,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 245,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "routes",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 245,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 245,
                                        "char": 47
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
                                                    "variable": "pattern",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "route",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 249,
                                                            "char": 37
                                                        },
                                                        "name": "getCompiledPattern",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 249,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 249,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 251,
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
                                                            "value": "pattern",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 251,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 251,
                                                        "char": 34
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "^",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 251,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 251,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 251,
                                                "char": 39
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
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 252,
                                                                            "char": 56
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 252,
                                                                        "char": 56
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "arguments",
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 252,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 252,
                                                                        "char": 67
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "matches",
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 252,
                                                                            "char": 76
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 252,
                                                                        "char": 76
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 252,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 252,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 253,
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
                                                            "variable": "routeFound",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 254,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "arguments",
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 254,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 254,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 254,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 255,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 260,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "routeFound",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 260,
                                                "char": 31
                                            },
                                            "statements": [
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
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 261,
                                                                    "char": 45
                                                                },
                                                                "name": "getBeforeMatch",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 261,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 261,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 263,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not-identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "beforeMatch",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 263,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 263,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 263,
                                                        "char": 45
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
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 267,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 267,
                                                                                "char": 61
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 267,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 267,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 267,
                                                                "char": 63
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
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 270,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 270,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 270,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 271,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 276,
                                                            "char": 27
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
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 277,
                                                                                    "char": 40
                                                                                },
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 277,
                                                                                "char": 40
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "array",
                                                                                    "left": [
                                                                                        {
                                                                                            "value": {
                                                                                                "type": "variable",
                                                                                                "value": "arguments",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                "line": 279,
                                                                                                "char": 42
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                            "line": 279,
                                                                                            "char": 42
                                                                                        },
                                                                                        {
                                                                                            "value": {
                                                                                                "type": "variable",
                                                                                                "value": "route",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                "line": 280,
                                                                                                "char": 38
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                            "line": 280,
                                                                                            "char": 38
                                                                                        },
                                                                                        {
                                                                                            "value": {
                                                                                                "type": "variable",
                                                                                                "value": "this",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                "line": 282,
                                                                                                "char": 29
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                            "line": 282,
                                                                                            "char": 29
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 283,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 283,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 283,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 283,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 284,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 285,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 287,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "routeFound",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 287,
                                                "char": 31
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
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 291,
                                                                    "char": 39
                                                                },
                                                                "name": "getPaths",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 291,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 291,
                                                            "char": 50
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "parts",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "paths",
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 292,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 292,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 297,
                                                    "char": 22
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
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 297,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 297,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 297,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 297,
                                                        "char": 48
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
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 301,
                                                                            "char": 48
                                                                        },
                                                                        "name": "getConverters",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 301,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 301,
                                                                    "char": 64
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 303,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "for",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "paths",
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 303,
                                                                "char": 53
                                                            },
                                                            "key": "part",
                                                            "value": "position",
                                                            "reverse": 0,
                                                            "statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "fetch",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "matchPosition",
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 304,
                                                                            "char": 71
                                                                        },
                                                                        "right": {
                                                                            "type": "array-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "matches",
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 304,
                                                                                "char": 60
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "position",
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 304,
                                                                                "char": 69
                                                                            },
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 304,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 304,
                                                                        "char": 71
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "fetch",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "converter",
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 308,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "converters",
                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                        "line": 308,
                                                                                        "char": 63
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "part",
                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                        "line": 308,
                                                                                        "char": 68
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 308,
                                                                                    "char": 70
                                                                                },
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 308,
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
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                    "line": 309,
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
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                            "line": 310,
                                                                                                            "char": 50
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                        "line": 310,
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
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                                        "line": 311,
                                                                                                                        "char": 55
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                                    "line": 311,
                                                                                                                    "char": 55
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                            "line": 312,
                                                                                                            "char": 37
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                        "line": 312,
                                                                                                        "char": 37
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                "line": 312,
                                                                                                "char": 38
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                            "line": 312,
                                                                                            "char": 38
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 313,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "else_statements": [
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
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                    "line": 317,
                                                                                                    "char": 51
                                                                                                }
                                                                                            ],
                                                                                            "expr": {
                                                                                                "type": "variable",
                                                                                                "value": "matchPosition",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                "line": 317,
                                                                                                "char": 68
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                            "line": 317,
                                                                                            "char": 68
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 318,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 319,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "else_statements": [
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "fetch",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "converter",
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 323,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "converters",
                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                        "line": 323,
                                                                                        "char": 63
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "part",
                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                        "line": 323,
                                                                                        "char": 68
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 323,
                                                                                    "char": 70
                                                                                },
                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                "line": 323,
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
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                    "line": 324,
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
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                            "line": 325,
                                                                                                            "char": 50
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                        "line": 325,
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
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                                        "line": 326,
                                                                                                                        "char": 50
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                                    "line": 326,
                                                                                                                    "char": 50
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                            "line": 327,
                                                                                                            "char": 37
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                        "line": 327,
                                                                                                        "char": 37
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                                "line": 327,
                                                                                                "char": 38
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                            "line": 327,
                                                                                            "char": 38
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                                    "line": 328,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 329,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 330,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 335,
                                                            "char": 27
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
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 335,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 335,
                                                                    "char": 52
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 336,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 338,
                                                    "char": 23
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
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 338,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 338,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 340,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 341,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 342,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 348,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "routeFound",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 348,
                                        "char": 27
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
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 349,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 349,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 350,
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
                                                    "property": "wasMatched",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 351,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 351,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 356,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
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
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 356,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "defaultModule",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 356,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 356,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 356,
                                                    "char": 55
                                                },
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "task",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 357,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "defaultTask",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 357,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 357,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 357,
                                                    "char": 51
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
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 358,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "defaultAction",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 358,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 358,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 358,
                                                    "char": 55
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
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 359,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "defaultParams",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 359,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 359,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 359,
                                                    "char": 55
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 361,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 361,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 362,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 363,
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
                                            "variable": "parts",
                                            "expr": {
                                                "type": "variable",
                                                "value": "arguments",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 364,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 364,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 365,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 367,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "moduleName",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 367,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 367,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "taskName",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 368,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 368,
                                    "char": 28
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "actionName",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 369,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 369,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 374,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "moduleName",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 374,
                                    "char": 44
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "parts",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 374,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "module",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 374,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 374,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 374,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "parts",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 375,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "module",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 375,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 375,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 376,
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
                                            "variable": "moduleName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 377,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultModule",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 377,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 377,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 377,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 378,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 383,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "taskName",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 383,
                                    "char": 40
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "parts",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 383,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "task",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 383,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 383,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 383,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "parts",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 384,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "task",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 384,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 384,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 385,
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
                                            "variable": "taskName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 386,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultTask",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 386,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 386,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 386,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 387,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 392,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "actionName",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 392,
                                    "char": 44
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "parts",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 392,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "action",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 392,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 392,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 392,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "parts",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 393,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "action",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 393,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 393,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 394,
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
                                            "variable": "actionName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 395,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultAction",
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 395,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 395,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 395,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 396,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 401,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 401,
                                    "char": 40
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "parts",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 401,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 401,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 401,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 401,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 402,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 402,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 402,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 402,
                                        "char": 39
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
                                                        "name": "substr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "cast",
                                                                    "left": "string",
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "params",
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 404,
                                                                        "char": 36
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 404,
                                                                    "char": 36
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 404,
                                                                "char": 36
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                    "line": 406,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 406,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 406,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 406,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 408,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "strParams",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 408,
                                                "char": 30
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
                                                                            "type": "scall",
                                                                            "dynamic-class": 0,
                                                                            "class": "Route",
                                                                            "dynamic": 0,
                                                                            "name": "getDelimiter",
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 409,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 409,
                                                                        "char": 63
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "strParams",
                                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                            "line": 409,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                        "line": 409,
                                                                        "char": 74
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 409,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 409,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 410,
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
                                                            "variable": "params",
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                                "line": 411,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 411,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                    "line": 412,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 413,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 415,
                                    "char": 17
                                },
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "parts",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 415,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 415,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 415,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 416,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 418,
                            "char": 10
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
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 418,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 418,
                                        "char": 24
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 418,
                                "char": 26
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
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 419,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 419,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "parts",
                                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                            "line": 419,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                        "line": 419,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 419,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 419,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 420,
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
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parts",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 421,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 421,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 422,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 424,
                            "char": 11
                        },
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
                                        "value": "moduleName",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 424,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 424,
                                    "char": 38
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "task",
                                    "expr": {
                                        "type": "variable",
                                        "value": "taskName",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 425,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 425,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "action",
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionName",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 426,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 426,
                                    "char": 38
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "params",
                                    "expr": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 427,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 427,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 428,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Handles routing information received from command-line arguments\n     *\n     * @param array arguments\n     *",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 227,
                    "last-line": 432,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 433,
                            "char": 55
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
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 435,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 435,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 436,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default action name\n     *",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 433,
                    "last-line": 440,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 441,
                            "char": 55
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
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 443,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 443,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 444,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the name of the default module\n     *",
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 441,
                    "last-line": 459,
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
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 460,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "module",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 462,
                                    "char": 19
                                },
                                {
                                    "variable": "task",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 462,
                                    "char": 25
                                },
                                {
                                    "variable": "action",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 462,
                                    "char": 33
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 462,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 465,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "module",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 465,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 465,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "module",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 465,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 465,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 465,
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
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 466,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 466,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 467,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 470,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "task",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 470,
                                    "char": 39
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 470,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "task",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 470,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 470,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 470,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "defaultTask",
                                            "expr": {
                                                "type": "variable",
                                                "value": "task",
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 471,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 471,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 472,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 475,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "action",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 475,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 475,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "action",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 475,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 475,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 475,
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
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 476,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 476,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 477,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 480,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 480,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 480,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 480,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 480,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 480,
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
                                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                                "line": 481,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                                            "line": 481,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 482,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 484,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 484,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 485,
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
                                    "value": "Router",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 461,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 461,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 461,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 460,
                    "last-line": 489,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 490,
                            "char": 51
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
                                    "property": "defaultTask",
                                    "expr": {
                                        "type": "variable",
                                        "value": "taskName",
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 492,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 492,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 493,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 491,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 490,
                    "last-line": 497,
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
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 498,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 498,
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
                                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                                        "line": 500,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 500,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 501,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 499,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 498,
                    "last-line": 505,
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
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 508,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "wasMatched",
                                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                                    "line": 508,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 508,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Cli\/Router.zep",
                            "line": 509,
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
                                "file": "\/app\/phalcon\/Cli\/Router.zep",
                                "line": 507,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router.zep",
                        "line": 507,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router.zep",
                    "line": 506,
                    "last-line": 510,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Cli\/Router.zep",
            "line": 38,
            "char": 5
        },
        "file": "\/app\/phalcon\/Cli\/Router.zep",
        "line": 38,
        "char": 5
    }
]