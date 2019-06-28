[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Router",
        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
        "line": 60,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Router\\Group\n *\n * Helper class to create a group of routes with common attributes\n *\n *```php\n * $router = new \\Phalcon\\Mvc\\Router();\n *\n * \/\/Create a group with a common module and controller\n * $blog = new Group(\n *     [\n *         \"module\"     => \"blog\",\n *         \"controller\" => \"index\",\n *     ]\n * );\n *\n * \/\/All the routes start with \/blog\n * $blog->setPrefix(\"\/blog\");\n *\n * \/\/Add a route to the group\n * $blog->add(\n *     \"\/save\",\n *     [\n *         \"action\" => \"save\",\n *     ]\n * );\n *\n * \/\/Add another route to the group\n * $blog->add(\n *     \"\/edit\/{id}\",\n *     [\n *         \"action\" => \"edit\",\n *     ]\n * );\n *\n * \/\/This route maps to a controller different than the default\n * $blog->add(\n *     \"\/blog\",\n *     [\n *         \"controller\" => \"about\",\n *         \"action\"     => \"index\",\n *     ]\n * );\n *\n * \/\/Add the group to the router\n * $router->mount($blog);\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
        "line": 61,
        "char": 5
    },
    {
        "type": "class",
        "name": "Group",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "GroupInterface",
                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                "line": 62,
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
                    "name": "beforeMatch",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 64,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "hostname",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 65,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "paths",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 66,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "prefix",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 67,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "routes",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 71,
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
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 72,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 72,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 74,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 74,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 74,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 74,
                                    "char": 35
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 74,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 74,
                                        "char": 51
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 74,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 74,
                                    "char": 60
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 74,
                                "char": 60
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "paths",
                                            "expr": {
                                                "type": "variable",
                                                "value": "paths",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 75,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 75,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 78,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 78,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 78,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "initialize",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 78,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 78,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 78,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 79,
                                            "char": 18
                                        },
                                        "name": "initialize",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 79,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 79,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 79,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 81,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Router\\Group constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 72,
                    "last-line": 89,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 90,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 90,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 90,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 90,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 90,
                            "char": 82
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 92,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 92,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 92,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 92,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 92,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "httpMethods",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 92,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 92,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 92,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 93,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router on any HTTP method\n     *\n     *```php\n     * $router->add(\"\/about\", \"About::index\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 91,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 91,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 91,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 90,
                    "last-line": 99,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 100,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 100,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 100,
                            "char": 65
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 102,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 102,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 102,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 102,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 102,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "CONNECT",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 102,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 102,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 102,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is CONNECT\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 101,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 101,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 100,
                    "last-line": 109,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 110,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 110,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 110,
                            "char": 64
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 112,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 112,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 112,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 112,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 112,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "DELETE",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 112,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 112,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 112,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 113,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is DELETE\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 111,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 111,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 111,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 110,
                    "last-line": 119,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 120,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 120,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 120,
                            "char": 61
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 122,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 122,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 122,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 122,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 122,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "GET",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 122,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 122,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 122,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 123,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is GET\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 121,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 121,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 121,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 120,
                    "last-line": 129,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 130,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 130,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 130,
                            "char": 62
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 132,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 132,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 132,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 132,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 132,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "HEAD",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 132,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 132,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 132,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 133,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is HEAD\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 131,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 131,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 131,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 130,
                    "last-line": 139,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 140,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 140,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 140,
                            "char": 65
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 142,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 142,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 142,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 142,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 142,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "OPTIONS",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 142,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 142,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 142,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Add a route to the router that only match if the HTTP method is OPTIONS\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 141,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 141,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 140,
                    "last-line": 149,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 150,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 150,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 150,
                            "char": 63
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 152,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 152,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 152,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 152,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 152,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PATCH",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 152,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 152,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 152,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 153,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is PATCH\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 151,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 151,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 151,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 150,
                    "last-line": 159,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 160,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 160,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 160,
                            "char": 62
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 162,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 162,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 162,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 162,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 162,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "POST",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 162,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 162,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 162,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 163,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is POST\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 161,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 161,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 161,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 160,
                    "last-line": 169,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 170,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 170,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 170,
                            "char": 63
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 172,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 172,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 172,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 172,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 172,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PURGE",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 172,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 172,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 172,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 173,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is PURGE\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 171,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 171,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 171,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 170,
                    "last-line": 179,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 180,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 180,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 180,
                            "char": 61
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 182,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 182,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 182,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 182,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 182,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PUT",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 182,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 182,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 182,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 183,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is PUT\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 181,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 181,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 181,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 180,
                    "last-line": 189,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 190,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 190,
                            "char": 63
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 192,
                                    "char": 21
                                },
                                "name": "addRoute",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 192,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 192,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 192,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 192,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "TRACE",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 192,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 192,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 192,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 193,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route to the router that only match if the HTTP method is TRACE\n     *\n     * @param string|array paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 191,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 191,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 191,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 190,
                    "last-line": 199,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 200,
                            "char": 54
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
                                    "property": "beforeMatch",
                                    "expr": {
                                        "type": "variable",
                                        "value": "beforeMatch",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 202,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 202,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 204,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 204,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 205,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 201,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 201,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 201,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 200,
                    "last-line": 209,
                    "char": 20
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
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 212,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 212,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 213,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes all the pre-defined routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 211,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 210,
                    "last-line": 217,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBeforeMatch",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 220,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "beforeMatch",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 220,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 220,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 221,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the 'before match' callback if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "callable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 219,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 219,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 218,
                    "last-line": 225,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHostname",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 228,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "hostname",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 228,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 228,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 229,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the hostname restriction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 227,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 227,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 226,
                    "last-line": 233,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPaths",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 236,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "paths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 236,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 236,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 237,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the common paths defined for this group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 234,
                                "char": 41
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 235,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 235,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 234,
                    "last-line": 241,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrefix",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 244,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "prefix",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 244,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 244,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 245,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the common prefix for all the routes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 243,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 243,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 242,
                    "last-line": 249,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 252,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routes",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 252,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 252,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 253,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the routes added to the group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 251,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 251,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 251,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 250,
                    "last-line": 257,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 258,
                            "char": 48
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
                                    "property": "hostname",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hostname",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 260,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 260,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 262,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 262,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 263,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 259,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 259,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 259,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 258,
                    "last-line": 267,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 268,
                            "char": 39
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
                                    "property": "paths",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paths",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 270,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 270,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 272,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 272,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 273,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set common paths for all the routes in the group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "GroupInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 269,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 269,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 269,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 268,
                    "last-line": 277,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 278,
                            "char": 44
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
                                    "property": "prefix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 280,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 280,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 282,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 282,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 283,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 279,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 279,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 279,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 278,
                    "last-line": 287,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "addRoute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 288,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 288,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 288,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "httpMethods",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 288,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 288,
                            "char": 90
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "mergedPaths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 290,
                                    "char": 24
                                },
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 290,
                                    "char": 31
                                },
                                {
                                    "variable": "defaultPaths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 290,
                                    "char": 45
                                },
                                {
                                    "variable": "processedPaths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 290,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 295,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "defaultPaths",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 295,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 295,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 295,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 295,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 297,
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
                                        "value": "defaultPaths",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 297,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 297,
                                    "char": 33
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 297,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 297,
                                "char": 41
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
                                                "value": "paths",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 298,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 298,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 298,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 298,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "processedPaths",
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
                                                                    "value": "paths",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                                    "line": 299,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                                "line": 299,
                                                                "char": 64
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                        "line": 299,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 299,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 300,
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
                                                    "variable": "processedPaths",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "paths",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                        "line": 301,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 301,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 302,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 304,
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
                                                "value": "processedPaths",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 304,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 304,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 304,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 304,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "mergedPaths",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "defaultPaths",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                                    "line": 308,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                                "line": 308,
                                                                "char": 59
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "processedPaths",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                                    "line": 308,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                                "line": 308,
                                                                "char": 75
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                        "line": 308,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 308,
                                                    "char": 76
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 309,
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
                                                    "variable": "mergedPaths",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "defaultPaths",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                        "line": 310,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 310,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 311,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 312,
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
                                            "variable": "mergedPaths",
                                            "expr": {
                                                "type": "variable",
                                                "value": "paths",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 313,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 313,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 314,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 319,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                            "line": 319,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "prefix",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                            "line": 319,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                        "line": 319,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "pattern",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                        "line": 319,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 319,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 319,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "mergedPaths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 319,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 319,
                                                "char": 66
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "httpMethods",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                    "line": 319,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                                "line": 319,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 319,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 319,
                                    "char": 80
                                },
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "routes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "route",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 320,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 320,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 322,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 322,
                                    "char": 15
                                },
                                "name": "setGroup",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                            "line": 322,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                        "line": 322,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 322,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 324,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "route",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 324,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                            "line": 325,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a route applying the common attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                    "line": 289,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                                "line": 289,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                        "line": 289,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
                    "line": 288,
                    "last-line": 326,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
            "line": 61,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Router\/Group.zep",
        "line": 61,
        "char": 5
    }
]