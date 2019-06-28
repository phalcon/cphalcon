[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Router",
        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                "line": 13,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Router\\Route\n *\n * This class represents every route added to the router\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Route",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "RouteInterface",
                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                "line": 21,
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
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 23,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "compiledPattern",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 24,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "converters",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 25,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "group",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 26,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "hostname",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 27,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "id",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 27,
                            "char": 24
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 28,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "methods",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 29,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "match",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 30,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 31,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "paths",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 32,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "pattern",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 33,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "uniqueId",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 33,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 37,
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
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 38,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 38,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 38,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 38,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 38,
                            "char": 90
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "routeId",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 40,
                                    "char": 20
                                },
                                {
                                    "variable": "uniqueId",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 40,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 43,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 43,
                                    "char": 14
                                },
                                "name": "reConfigure",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 43,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 43,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 43,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 43,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 43,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 46,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 46,
                                    "char": 14
                                },
                                "name": "via",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "httpMethods",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 46,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 46,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 46,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 49,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uniqueId",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 49,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "uniqueId",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 49,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 49,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 49,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 52,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "routeId",
                                    "expr": {
                                        "type": "variable",
                                        "value": "uniqueId",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 52,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 52,
                                    "char": 31
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "id",
                                    "expr": {
                                        "type": "variable",
                                        "value": "routeId",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 53,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 53,
                                    "char": 31
                                },
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "uniqueId",
                                    "expr": {
                                        "type": "add",
                                        "left": {
                                            "type": "variable",
                                            "value": "uniqueId",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 54,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 54,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 54,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 54,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Router\\Route constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 38,
                    "last-line": 80,
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
                            "name": "callback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 81,
                            "char": 45
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
                                        "value": "callback",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 83,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 83,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 85,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 85,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 86,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a callback that is called if the route is matched.\n     * The developer can implement any arbitrary conditions here\n     * If the callback returns false the route is treated as not matched\n     *\n     *```php\n     * $router->add(\n     *     \"\/login\",\n     *     [\n     *         \"module\"     => \"admin\",\n     *         \"controller\" => \"session\",\n     *     ]\n     * )->beforeMatch(\n     *     function ($uri, $route) {\n     *         \/\/ Check if the request was made with Ajax\n     *         if ($_SERVER[\"HTTP_X_REQUESTED_WITH\"] === \"xmlhttprequest\") {\n     *             return false;\n     *         }\n     *\n     *         return true;\n     *     }\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 82,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 82,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 82,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 81,
                    "last-line": 90,
                    "char": 19
                },
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 91,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "idPattern",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 93,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 96,
                            "char": 10
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
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 96,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 96,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": ":",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 96,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 96,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 96,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "idPattern",
                                            "expr": {
                                                "type": "string",
                                                "value": "\/([\\\\w0-9\\\\_\\\\-]+)",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 98,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 98,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 101,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 101,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 101,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/:module",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 101,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 101,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 101,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pattern",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/:module",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 102,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 102,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 102,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 102,
                                                                "char": 62
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 102,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 102,
                                                                "char": 71
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 102,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 102,
                                                    "char": 72
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 103,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 106,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 106,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 106,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/:controller",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 106,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 106,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 106,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pattern",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/:controller",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 107,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 107,
                                                                "char": 55
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 107,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 107,
                                                                "char": 66
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 107,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 107,
                                                                "char": 75
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 107,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 107,
                                                    "char": 76
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 108,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 111,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 111,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 111,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/:namespace",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 111,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 111,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 111,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pattern",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/:namespace",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 112,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 112,
                                                                "char": 54
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 112,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 112,
                                                                "char": 65
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 112,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 112,
                                                                "char": 74
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 112,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 112,
                                                    "char": 75
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 113,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 116,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 116,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 116,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/:action",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 116,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 116,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 116,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pattern",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/:action",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 117,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 117,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 117,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 117,
                                                                "char": 62
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 117,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 117,
                                                                "char": 71
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 117,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 117,
                                                    "char": 72
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 118,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 121,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 121,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 121,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/:params",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 121,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 121,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 121,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pattern",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/:params",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 122,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 122,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "(\/.*)*",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 122,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 122,
                                                                "char": 59
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 122,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 122,
                                                                "char": 68
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 122,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 122,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 123,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 126,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 126,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 126,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/:int",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 126,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 126,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 126,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pattern",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/:int",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 127,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 127,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/([0-9]+)",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 127,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 127,
                                                                "char": 59
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 127,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 127,
                                                                "char": 68
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 127,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 127,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 128,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 129,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 135,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "fcall",
                                    "name": "memstr",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 135,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 135,
                                            "char": 26
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "(",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 135,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 135,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 135,
                                    "char": 32
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "memstr",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 135,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 135,
                                            "char": 48
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "[",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 135,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 135,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 135,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 135,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "#^",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 136,
                                                "char": 23
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 136,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 136,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "$#",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 136,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 136,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 137,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 139,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "pattern",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 139,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 140,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 92,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 92,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 91,
                    "last-line": 144,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 145,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "converter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 145,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "converters",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 147,
                                            "char": 34
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "converter",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 147,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 147,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 149,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 149,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 150,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 146,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 146,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 146,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 145,
                    "last-line": 154,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "extractNamedParams",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 155,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "char",
                            "variables": [
                                {
                                    "variable": "ch",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 157,
                                    "char": 16
                                },
                                {
                                    "variable": "prevCh",
                                    "expr": {
                                        "type": "char",
                                        "value": "\\0",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 157,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 157,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 158,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "tmp",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 158,
                                    "char": 16
                                },
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 158,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 159,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "notValid",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 159,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 160,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "cursor",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 160,
                                    "char": 19
                                },
                                {
                                    "variable": "cursorVar",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 160,
                                    "char": 30
                                },
                                {
                                    "variable": "marker",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 160,
                                    "char": 38
                                },
                                {
                                    "variable": "bracketCount",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 160,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 160,
                                    "char": 56
                                },
                                {
                                    "variable": "parenthesesCount",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 160,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 160,
                                    "char": 78
                                },
                                {
                                    "variable": "foundPattern",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 160,
                                        "char": 96
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 160,
                                    "char": 96
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 161,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "intermediate",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 161,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 161,
                                    "char": 29
                                },
                                {
                                    "variable": "numberMatches",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 161,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 161,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 162,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 162,
                                    "char": 21
                                },
                                {
                                    "variable": "item",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 162,
                                    "char": 27
                                },
                                {
                                    "variable": "variable",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 162,
                                    "char": 37
                                },
                                {
                                    "variable": "regexp",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 162,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 164,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "strlen",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 164,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 164,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 164,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 164,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 164,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 165,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 166,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 168,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "matches",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 168,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 168,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "route",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 169,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 169,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 171,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "pattern",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 171,
                                "char": 35
                            },
                            "key": "cursor",
                            "value": "ch",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "parenthesesCount",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 172,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 172,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 172,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "ch",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 173,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "char",
                                                    "value": "{",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 173,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 173,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "bracketCount",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 174,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 174,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 174,
                                                        "char": 42
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "marker",
                                                                    "expr": {
                                                                        "type": "add",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "cursor",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 175,
                                                                            "char": 45
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "1",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 175,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 175,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 175,
                                                                    "char": 48
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "intermediate",
                                                                    "expr": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 176,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 176,
                                                                    "char": 45
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "notValid",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 177,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 177,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 178,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 180,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "incr",
                                                            "variable": "bracketCount",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 180,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 181,
                                                    "char": 17
                                                }
                                            ],
                                            "elseif_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "ch",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 181,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "char",
                                                            "value": "}",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 181,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 181,
                                                        "char": 35
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "bracketCount",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 182,
                                                                    "char": 39
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 184,
                                                            "char": 22
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "greater",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "intermediate",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 184,
                                                                    "char": 37
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 184,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 184,
                                                                "char": 41
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "equals",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "bracketCount",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 185,
                                                                            "char": 42
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "0",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 185,
                                                                            "char": 46
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 185,
                                                                        "char": 46
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "incr",
                                                                                    "variable": "numberMatches",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 186,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "variable",
                                                                                    "expr": {
                                                                                        "type": "null",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                        "line": 187,
                                                                                        "char": 48
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 187,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "regexp",
                                                                                    "expr": {
                                                                                        "type": "null",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                        "line": 188,
                                                                                        "char": 46
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 188,
                                                                                    "char": 46
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "item",
                                                                                    "expr": {
                                                                                        "type": "cast",
                                                                                        "left": "string",
                                                                                        "right": {
                                                                                            "type": "fcall",
                                                                                            "name": "substr",
                                                                                            "call-type": 1,
                                                                                            "parameters": [
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "variable",
                                                                                                        "value": "pattern",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 189,
                                                                                                        "char": 63
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 189,
                                                                                                    "char": 63
                                                                                                },
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "variable",
                                                                                                        "value": "marker",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 189,
                                                                                                        "char": 71
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 189,
                                                                                                    "char": 71
                                                                                                },
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "sub",
                                                                                                        "left": {
                                                                                                            "type": "variable",
                                                                                                            "value": "cursor",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 189,
                                                                                                            "char": 80
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "variable",
                                                                                                            "value": "marker",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 189,
                                                                                                            "char": 88
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 189,
                                                                                                        "char": 88
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 189,
                                                                                                    "char": 88
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 189,
                                                                                            "char": 89
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                        "line": 189,
                                                                                        "char": 89
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 189,
                                                                                    "char": 89
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 191,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "type": "for",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "item",
                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                "line": 191,
                                                                                "char": 55
                                                                            },
                                                                            "key": "cursorVar",
                                                                            "value": "ch",
                                                                            "reverse": 0,
                                                                            "statements": [
                                                                                {
                                                                                    "type": "if",
                                                                                    "expr": {
                                                                                        "type": "equals",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "ch",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 192,
                                                                                            "char": 40
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "char",
                                                                                            "value": "\\0",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 192,
                                                                                            "char": 46
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                        "line": 192,
                                                                                        "char": 46
                                                                                    },
                                                                                    "statements": [
                                                                                        {
                                                                                            "type": "break",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 194,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 196,
                                                                                    "char": 34
                                                                                },
                                                                                {
                                                                                    "type": "if",
                                                                                    "expr": {
                                                                                        "type": "and",
                                                                                        "left": {
                                                                                            "type": "equals",
                                                                                            "left": {
                                                                                                "type": "variable",
                                                                                                "value": "cursorVar",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 196,
                                                                                                "char": 47
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "int",
                                                                                                "value": "0",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 196,
                                                                                                "char": 52
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 196,
                                                                                            "char": 52
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "not",
                                                                                            "left": {
                                                                                                "type": "list",
                                                                                                "left": {
                                                                                                    "type": "or",
                                                                                                    "left": {
                                                                                                        "type": "list",
                                                                                                        "left": {
                                                                                                            "type": "and",
                                                                                                            "left": {
                                                                                                                "type": "greater-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 60
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "a",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 66
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 196,
                                                                                                                "char": 66
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "less-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 71
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "z",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 75
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 196,
                                                                                                                "char": 75
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 196,
                                                                                                            "char": 75
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 196,
                                                                                                        "char": 78
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "list",
                                                                                                        "left": {
                                                                                                            "type": "and",
                                                                                                            "left": {
                                                                                                                "type": "greater-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 84
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "A",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 90
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 196,
                                                                                                                "char": 90
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "less-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 95
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "Z",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 196,
                                                                                                                    "char": 99
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 196,
                                                                                                                "char": 99
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 196,
                                                                                                            "char": 99
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 196,
                                                                                                        "char": 100
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 196,
                                                                                                    "char": 100
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 196,
                                                                                                "char": 102
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 196,
                                                                                            "char": 102
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                        "line": 196,
                                                                                        "char": 102
                                                                                    },
                                                                                    "statements": [
                                                                                        {
                                                                                            "type": "let",
                                                                                            "assignments": [
                                                                                                {
                                                                                                    "assign-type": "variable",
                                                                                                    "operator": "assign",
                                                                                                    "variable": "notValid",
                                                                                                    "expr": {
                                                                                                        "type": "bool",
                                                                                                        "value": "true",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 197,
                                                                                                        "char": 56
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 197,
                                                                                                    "char": 56
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 199,
                                                                                            "char": 41
                                                                                        },
                                                                                        {
                                                                                            "type": "break",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 200,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 202,
                                                                                    "char": 34
                                                                                },
                                                                                {
                                                                                    "type": "if",
                                                                                    "expr": {
                                                                                        "type": "or",
                                                                                        "left": {
                                                                                            "type": "or",
                                                                                            "left": {
                                                                                                "type": "or",
                                                                                                "left": {
                                                                                                    "type": "or",
                                                                                                    "left": {
                                                                                                        "type": "or",
                                                                                                        "left": {
                                                                                                            "type": "list",
                                                                                                            "left": {
                                                                                                                "type": "and",
                                                                                                                "left": {
                                                                                                                    "type": "greater-equal",
                                                                                                                    "left": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "ch",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 40
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "a",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 46
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 46
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "less-equal",
                                                                                                                    "left": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "ch",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 51
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "z",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 55
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 55
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 202,
                                                                                                                "char": 55
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 202,
                                                                                                            "char": 58
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "list",
                                                                                                            "left": {
                                                                                                                "type": "and",
                                                                                                                "left": {
                                                                                                                    "type": "greater-equal",
                                                                                                                    "left": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "ch",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 64
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "A",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 70
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 70
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "less-equal",
                                                                                                                    "left": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "ch",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 75
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "Z",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 202,
                                                                                                                        "char": 79
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 79
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 202,
                                                                                                                "char": 79
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 202,
                                                                                                            "char": 82
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 202,
                                                                                                        "char": 82
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "list",
                                                                                                        "left": {
                                                                                                            "type": "and",
                                                                                                            "left": {
                                                                                                                "type": "greater-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 88
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "0",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 94
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 202,
                                                                                                                "char": 94
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "less-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 99
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "9",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 202,
                                                                                                                    "char": 102
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 202,
                                                                                                                "char": 102
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 202,
                                                                                                            "char": 102
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 202,
                                                                                                        "char": 105
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 202,
                                                                                                    "char": 105
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "equals",
                                                                                                    "left": {
                                                                                                        "type": "variable",
                                                                                                        "value": "ch",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 202,
                                                                                                        "char": 111
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "char",
                                                                                                        "value": "-",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 202,
                                                                                                        "char": 117
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 202,
                                                                                                    "char": 117
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 202,
                                                                                                "char": 117
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "equals",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "ch",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 202,
                                                                                                    "char": 123
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "char",
                                                                                                    "value": "_",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 202,
                                                                                                    "char": 129
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 202,
                                                                                                "char": 129
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 202,
                                                                                            "char": 129
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "equals",
                                                                                            "left": {
                                                                                                "type": "variable",
                                                                                                "value": "ch",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 202,
                                                                                                "char": 135
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "char",
                                                                                                "value": ":",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 202,
                                                                                                "char": 141
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 202,
                                                                                            "char": 141
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                        "line": 202,
                                                                                        "char": 141
                                                                                    },
                                                                                    "statements": [
                                                                                        {
                                                                                            "type": "if",
                                                                                            "expr": {
                                                                                                "type": "equals",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "ch",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 203,
                                                                                                    "char": 44
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "char",
                                                                                                    "value": ":",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 203,
                                                                                                    "char": 49
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 203,
                                                                                                "char": 49
                                                                                            },
                                                                                            "statements": [
                                                                                                {
                                                                                                    "type": "let",
                                                                                                    "assignments": [
                                                                                                        {
                                                                                                            "assign-type": "variable",
                                                                                                            "operator": "assign",
                                                                                                            "variable": "variable",
                                                                                                            "expr": {
                                                                                                                "type": "cast",
                                                                                                                "left": "string",
                                                                                                                "right": {
                                                                                                                    "type": "fcall",
                                                                                                                    "name": "substr",
                                                                                                                    "call-type": 1,
                                                                                                                    "parameters": [
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "variable",
                                                                                                                                "value": "item",
                                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                "line": 204,
                                                                                                                                "char": 76
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                            "line": 204,
                                                                                                                            "char": 76
                                                                                                                        },
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "int",
                                                                                                                                "value": "0",
                                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                "line": 204,
                                                                                                                                "char": 79
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                            "line": 204,
                                                                                                                            "char": 79
                                                                                                                        },
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "variable",
                                                                                                                                "value": "cursorVar",
                                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                "line": 204,
                                                                                                                                "char": 90
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                            "line": 204,
                                                                                                                            "char": 90
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 204,
                                                                                                                    "char": 91
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 204,
                                                                                                                "char": 91
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 204,
                                                                                                            "char": 91
                                                                                                        },
                                                                                                        {
                                                                                                            "assign-type": "variable",
                                                                                                            "operator": "assign",
                                                                                                            "variable": "regexp",
                                                                                                            "expr": {
                                                                                                                "type": "cast",
                                                                                                                "left": "string",
                                                                                                                "right": {
                                                                                                                    "type": "fcall",
                                                                                                                    "name": "substr",
                                                                                                                    "call-type": 1,
                                                                                                                    "parameters": [
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "variable",
                                                                                                                                "value": "item",
                                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                "line": 205,
                                                                                                                                "char": 74
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                            "line": 205,
                                                                                                                            "char": 74
                                                                                                                        },
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "add",
                                                                                                                                "left": {
                                                                                                                                    "type": "variable",
                                                                                                                                    "value": "cursorVar",
                                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                    "line": 205,
                                                                                                                                    "char": 86
                                                                                                                                },
                                                                                                                                "right": {
                                                                                                                                    "type": "int",
                                                                                                                                    "value": "1",
                                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                    "line": 205,
                                                                                                                                    "char": 89
                                                                                                                                },
                                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                "line": 205,
                                                                                                                                "char": 89
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                            "line": 205,
                                                                                                                            "char": 89
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 205,
                                                                                                                    "char": 90
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 205,
                                                                                                                "char": 90
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 205,
                                                                                                            "char": 90
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 207,
                                                                                                    "char": 45
                                                                                                },
                                                                                                {
                                                                                                    "type": "break",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 208,
                                                                                                    "char": 37
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 209,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "else_statements": [
                                                                                        {
                                                                                            "type": "let",
                                                                                            "assignments": [
                                                                                                {
                                                                                                    "assign-type": "variable",
                                                                                                    "operator": "assign",
                                                                                                    "variable": "notValid",
                                                                                                    "expr": {
                                                                                                        "type": "bool",
                                                                                                        "value": "true",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 210,
                                                                                                        "char": 56
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 210,
                                                                                                    "char": 56
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 212,
                                                                                            "char": 41
                                                                                        },
                                                                                        {
                                                                                            "type": "break",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 213,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 214,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 216,
                                                                            "char": 30
                                                                        },
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "not",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "notValid",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 216,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                "line": 216,
                                                                                "char": 42
                                                                            },
                                                                            "statements": [
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "tmp",
                                                                                            "expr": {
                                                                                                "type": "variable",
                                                                                                "value": "numberMatches",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 217,
                                                                                                "char": 56
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 217,
                                                                                            "char": 56
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 219,
                                                                                    "char": 34
                                                                                },
                                                                                {
                                                                                    "type": "if",
                                                                                    "expr": {
                                                                                        "type": "and",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "variable",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 219,
                                                                                            "char": 46
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "regexp",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 219,
                                                                                            "char": 55
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                        "line": 219,
                                                                                        "char": 55
                                                                                    },
                                                                                    "statements": [
                                                                                        {
                                                                                            "type": "let",
                                                                                            "assignments": [
                                                                                                {
                                                                                                    "assign-type": "variable",
                                                                                                    "operator": "assign",
                                                                                                    "variable": "foundPattern",
                                                                                                    "expr": {
                                                                                                        "type": "int",
                                                                                                        "value": "0",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 220,
                                                                                                        "char": 57
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 220,
                                                                                                    "char": 57
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 222,
                                                                                            "char": 39
                                                                                        },
                                                                                        {
                                                                                            "type": "for",
                                                                                            "expr": {
                                                                                                "type": "variable",
                                                                                                "value": "regexp",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 222,
                                                                                                "char": 54
                                                                                            },
                                                                                            "value": "ch",
                                                                                            "reverse": 0,
                                                                                            "statements": [
                                                                                                {
                                                                                                    "type": "if",
                                                                                                    "expr": {
                                                                                                        "type": "equals",
                                                                                                        "left": {
                                                                                                            "type": "variable",
                                                                                                            "value": "ch",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 223,
                                                                                                            "char": 48
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "char",
                                                                                                            "value": "\\0",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 223,
                                                                                                            "char": 54
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 223,
                                                                                                        "char": 54
                                                                                                    },
                                                                                                    "statements": [
                                                                                                        {
                                                                                                            "type": "break",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 225,
                                                                                                            "char": 41
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 227,
                                                                                                    "char": 42
                                                                                                },
                                                                                                {
                                                                                                    "type": "if",
                                                                                                    "expr": {
                                                                                                        "type": "not",
                                                                                                        "left": {
                                                                                                            "type": "variable",
                                                                                                            "value": "foundPattern",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 227,
                                                                                                            "char": 58
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 227,
                                                                                                        "char": 58
                                                                                                    },
                                                                                                    "statements": [
                                                                                                        {
                                                                                                            "type": "if",
                                                                                                            "expr": {
                                                                                                                "type": "equals",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 228,
                                                                                                                    "char": 52
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "(",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 228,
                                                                                                                    "char": 57
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 228,
                                                                                                                "char": 57
                                                                                                            },
                                                                                                            "statements": [
                                                                                                                {
                                                                                                                    "type": "let",
                                                                                                                    "assignments": [
                                                                                                                        {
                                                                                                                            "assign-type": "variable",
                                                                                                                            "operator": "assign",
                                                                                                                            "variable": "foundPattern",
                                                                                                                            "expr": {
                                                                                                                                "type": "int",
                                                                                                                                "value": "1",
                                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                "line": 229,
                                                                                                                                "char": 69
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                            "line": 229,
                                                                                                                            "char": 69
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 230,
                                                                                                                    "char": 45
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 231,
                                                                                                            "char": 41
                                                                                                        }
                                                                                                    ],
                                                                                                    "else_statements": [
                                                                                                        {
                                                                                                            "type": "if",
                                                                                                            "expr": {
                                                                                                                "type": "equals",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 232,
                                                                                                                    "char": 52
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": ")",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 232,
                                                                                                                    "char": 57
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 232,
                                                                                                                "char": 57
                                                                                                            },
                                                                                                            "statements": [
                                                                                                                {
                                                                                                                    "type": "let",
                                                                                                                    "assignments": [
                                                                                                                        {
                                                                                                                            "assign-type": "variable",
                                                                                                                            "operator": "assign",
                                                                                                                            "variable": "foundPattern",
                                                                                                                            "expr": {
                                                                                                                                "type": "int",
                                                                                                                                "value": "2",
                                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                                "line": 233,
                                                                                                                                "char": 69
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                            "line": 233,
                                                                                                                            "char": 69
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 235,
                                                                                                                    "char": 53
                                                                                                                },
                                                                                                                {
                                                                                                                    "type": "break",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 236,
                                                                                                                    "char": 45
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 237,
                                                                                                            "char": 41
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 238,
                                                                                                    "char": 37
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 240,
                                                                                            "char": 38
                                                                                        },
                                                                                        {
                                                                                            "type": "if",
                                                                                            "expr": {
                                                                                                "type": "not-equals",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "foundPattern",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 240,
                                                                                                    "char": 54
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "int",
                                                                                                    "value": "2",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 240,
                                                                                                    "char": 58
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 240,
                                                                                                "char": 58
                                                                                            },
                                                                                            "statements": [
                                                                                                {
                                                                                                    "type": "let",
                                                                                                    "assignments": [
                                                                                                        {
                                                                                                            "assign-type": "variable",
                                                                                                            "operator": "concat-assign",
                                                                                                            "variable": "route",
                                                                                                            "expr": {
                                                                                                                "type": "concat",
                                                                                                                "left": {
                                                                                                                    "type": "concat",
                                                                                                                    "left": {
                                                                                                                        "type": "string",
                                                                                                                        "value": "(",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 241,
                                                                                                                        "char": 55
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "regexp",
                                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                        "line": 241,
                                                                                                                        "char": 64
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 241,
                                                                                                                    "char": 64
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "string",
                                                                                                                    "value": ")",
                                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                    "line": 241,
                                                                                                                    "char": 67
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 241,
                                                                                                                "char": 67
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 241,
                                                                                                            "char": 67
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 242,
                                                                                                    "char": 37
                                                                                                }
                                                                                            ],
                                                                                            "else_statements": [
                                                                                                {
                                                                                                    "type": "let",
                                                                                                    "assignments": [
                                                                                                        {
                                                                                                            "assign-type": "variable",
                                                                                                            "operator": "concat-assign",
                                                                                                            "variable": "route",
                                                                                                            "expr": {
                                                                                                                "type": "variable",
                                                                                                                "value": "regexp",
                                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                                "line": 243,
                                                                                                                "char": 59
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 243,
                                                                                                            "char": 59
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 244,
                                                                                                    "char": 37
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 246,
                                                                                            "char": 39
                                                                                        },
                                                                                        {
                                                                                            "type": "let",
                                                                                            "assignments": [
                                                                                                {
                                                                                                    "assign-type": "array-index",
                                                                                                    "operator": "assign",
                                                                                                    "variable": "matches",
                                                                                                    "index-expr": [
                                                                                                        {
                                                                                                            "type": "variable",
                                                                                                            "value": "variable",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 246,
                                                                                                            "char": 57
                                                                                                        }
                                                                                                    ],
                                                                                                    "expr": {
                                                                                                        "type": "variable",
                                                                                                        "value": "tmp",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 246,
                                                                                                        "char": 64
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 246,
                                                                                                    "char": 64
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 247,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "else_statements": [
                                                                                        {
                                                                                            "type": "let",
                                                                                            "assignments": [
                                                                                                {
                                                                                                    "assign-type": "variable",
                                                                                                    "operator": "concat-assign",
                                                                                                    "variable": "route",
                                                                                                    "expr": {
                                                                                                        "type": "string",
                                                                                                        "value": "([^\/]*)",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 248,
                                                                                                        "char": 56
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 248,
                                                                                                    "char": 56
                                                                                                },
                                                                                                {
                                                                                                    "assign-type": "array-index",
                                                                                                    "operator": "assign",
                                                                                                    "variable": "matches",
                                                                                                    "index-expr": [
                                                                                                        {
                                                                                                            "type": "variable",
                                                                                                            "value": "item",
                                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                            "line": 249,
                                                                                                            "char": 53
                                                                                                        }
                                                                                                    ],
                                                                                                    "expr": {
                                                                                                        "type": "variable",
                                                                                                        "value": "tmp",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 249,
                                                                                                        "char": 60
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 249,
                                                                                                    "char": 60
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 250,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 251,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "else_statements": [
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "concat-assign",
                                                                                            "variable": "route",
                                                                                            "expr": {
                                                                                                "type": "concat",
                                                                                                "left": {
                                                                                                    "type": "concat",
                                                                                                    "left": {
                                                                                                        "type": "string",
                                                                                                        "value": "{",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 252,
                                                                                                        "char": 47
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "variable",
                                                                                                        "value": "item",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                        "line": 252,
                                                                                                        "char": 54
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 252,
                                                                                                    "char": 54
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "string",
                                                                                                    "value": "}",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                    "line": 252,
                                                                                                    "char": 57
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                                "line": 252,
                                                                                                "char": 57
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                            "line": 252,
                                                                                            "char": 57
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                                    "line": 253,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 255,
                                                                            "char": 36
                                                                        },
                                                                        {
                                                                            "type": "continue",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 256,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 257,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 258,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 259,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 259,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 261,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "bracketCount",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 261,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 261,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 261,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "ch",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 262,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "char",
                                                    "value": "(",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 262,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 262,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "incr",
                                                            "variable": "parenthesesCount",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 263,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 264,
                                                    "char": 17
                                                }
                                            ],
                                            "elseif_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "ch",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 264,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "char",
                                                            "value": ")",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 264,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 264,
                                                        "char": 35
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "parenthesesCount",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 265,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 267,
                                                            "char": 22
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parenthesesCount",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 267,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 267,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 267,
                                                                "char": 46
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "incr",
                                                                            "variable": "numberMatches",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 268,
                                                                            "char": 44
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 269,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 270,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 271,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 271,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 273,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "bracketCount",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 273,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 273,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 273,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "incr",
                                                    "variable": "intermediate",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 274,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 275,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "parenthesesCount",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 276,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 276,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 276,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "prevCh",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 276,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "char",
                                                        "value": "\\\\",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 276,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 276,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 276,
                                                "char": 59
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "or",
                                                            "left": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "equals",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "ch",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 277,
                                                                        "char": 28
                                                                    },
                                                                    "right": {
                                                                        "type": "char",
                                                                        "value": ".",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 277,
                                                                        "char": 34
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 277,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "equals",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "ch",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 277,
                                                                        "char": 40
                                                                    },
                                                                    "right": {
                                                                        "type": "char",
                                                                        "value": "+",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 277,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 277,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 277,
                                                                "char": 46
                                                            },
                                                            "right": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "ch",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 277,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "char",
                                                                    "value": "|",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 277,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 277,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 277,
                                                            "char": 58
                                                        },
                                                        "right": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "ch",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 277,
                                                                "char": 64
                                                            },
                                                            "right": {
                                                                "type": "char",
                                                                "value": "#",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 277,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 277,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 277,
                                                        "char": 69
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "route",
                                                                    "expr": {
                                                                        "type": "char",
                                                                        "value": "\\\\",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 278,
                                                                        "char": 40
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 278,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 279,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 280,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 282,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "route",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "ch",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 282,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 282,
                                                    "char": 31
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "prevCh",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "ch",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 283,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 283,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 284,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 285,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 287,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "route",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 287,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 287,
                                        "char": 22
                                    },
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "matches",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 287,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 287,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 287,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 288,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Extracts parameters from a string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 155,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 156,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 156,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 155,
                    "last-line": 292,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 295,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "beforeMatch",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 295,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 295,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 296,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 294,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 294,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 293,
                    "last-line": 300,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCompiledPattern",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 303,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "compiledPattern",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 303,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 303,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 304,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the route's compiled pattern\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 302,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 302,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 301,
                    "last-line": 308,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConverters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 311,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "converters",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 311,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 311,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 312,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the router converter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 310,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 310,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 309,
                    "last-line": 316,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getGroup",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 319,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "group",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 319,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 319,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 320,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the group associated with the route\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "GroupInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 317,
                                    "char": 52
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 317,
                                "char": 52
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 318,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 318,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 317,
                    "last-line": 324,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHttpMethods",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 327,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "methods",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 327,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 327,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 328,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the HTTP methods that constraint matching the route\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 325,
                                "char": 47
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 326,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 326,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 325,
                    "last-line": 332,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 335,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "hostname",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 335,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 335,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 336,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the hostname restriction if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 334,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 334,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 333,
                    "last-line": 340,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMatch",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 343,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "match",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 343,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 343,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 344,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the 'match' callback if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "callable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 342,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 342,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 341,
                    "last-line": 348,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 351,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 351,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 351,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 352,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the route's name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 350,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 350,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 349,
                    "last-line": 356,
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 359,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "paths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 359,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 359,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 360,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 358,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 358,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 357,
                    "last-line": 364,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPattern",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 367,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "pattern",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 367,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 367,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 368,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the route's pattern\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 366,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 366,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 365,
                    "last-line": 372,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReversedPaths",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "array_flip",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 376,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "paths",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 377,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 377,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 377,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 377,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 378,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the paths using positions as keys and names as values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 374,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 374,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 373,
                    "last-line": 382,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRouteId",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 385,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "id",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 385,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 385,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 386,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the route's id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 384,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 384,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 383,
                    "last-line": 390,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getRoutePaths",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "paths",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 391,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 391,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "moduleName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 393,
                                    "char": 23
                                },
                                {
                                    "variable": "controllerName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 393,
                                    "char": 39
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 393,
                                    "char": 51
                                },
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 393,
                                    "char": 58
                                },
                                {
                                    "variable": "routePaths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 393,
                                    "char": 70
                                },
                                {
                                    "variable": "realClassName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 394,
                                    "char": 26
                                },
                                {
                                    "variable": "namespaceName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 394,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 396,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "paths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 396,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 396,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 396,
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
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 397,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 397,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 398,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 400,
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
                                        "value": "paths",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 400,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 400,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 400,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 400,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "moduleName",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 401,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 401,
                                            "char": 34
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "controllerName",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 402,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 402,
                                            "char": 38
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "actionName",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 403,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 403,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 406,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "parts",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "explode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "::",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 406,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 406,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "paths",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 406,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 406,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 406,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 406,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 409,
                                    "char": 18
                                },
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "parts",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 409,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 409,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 409,
                                        "char": 33
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "3",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 411,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "moduleName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 412,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 412,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 412,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 412,
                                                            "char": 46
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "controllerName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 413,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 413,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 413,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 413,
                                                            "char": 50
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "actionName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 414,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "2",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 414,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 414,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 414,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 415,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 417,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 417,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 417,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "controllerName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 418,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 418,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 418,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 418,
                                                            "char": 50
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "actionName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 419,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 419,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 419,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 419,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 420,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 422,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 422,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 422,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "controllerName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 423,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 423,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 423,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 423,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 424,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 425,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 425,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 427,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "routePaths",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 427,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 427,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 430,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "moduleName",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 430,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 430,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 430,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "routePaths",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "module",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 431,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "moduleName",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 431,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 431,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 432,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 435,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "controllerName",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 435,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 435,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 435,
                                        "char": 40
                                    },
                                    "statements": [
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
                                                            "value": "controllerName",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 437,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 437,
                                                        "char": 41
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\\\\",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 437,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 437,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 437,
                                                "char": 47
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "realClassName",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "get_class_ns",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "controllerName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 439,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 439,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 439,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 439,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 442,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "namespaceName",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "get_ns_class",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "controllerName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 442,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 442,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 442,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 442,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 445,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "namespaceName",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 445,
                                                        "char": 38
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "routePaths",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "string",
                                                                            "value": "namespace",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                            "line": 446,
                                                                            "char": 49
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "namespaceName",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 446,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 446,
                                                                    "char": 66
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 447,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 448,
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
                                                            "variable": "realClassName",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "controllerName",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 449,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 449,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 450,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 453,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "routePaths",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "controller",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 453,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "uncamelize",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "realClassName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 453,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 453,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 453,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 453,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 454,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 457,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "actionName",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 457,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 457,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 457,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "routePaths",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "action",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 458,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "actionName",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 458,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 458,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 459,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 460,
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
                                            "variable": "routePaths",
                                            "expr": {
                                                "type": "variable",
                                                "value": "paths",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 461,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 461,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 462,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 464,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "routePaths",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 464,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 464,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 464,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 464,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 464,
                                "char": 49
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
                                                    "value": "The route contains invalid paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 465,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 465,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 465,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 466,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 468,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "routePaths",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 468,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 469,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns routePaths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 392,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 392,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 391,
                    "last-line": 484,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "match",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "callback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 485,
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
                                    "property": "match",
                                    "expr": {
                                        "type": "variable",
                                        "value": "callback",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 487,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 487,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 489,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 489,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 490,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to set a callback to handle the request directly in the route\n     *\n     *```php\n     * $router->add(\n     *     \"\/help\",\n     *     []\n     * )->match(\n     *     function () {\n     *         return $this->getResponse()->redirect(\"https:\/\/support.google.com\/\", true);\n     *     }\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 486,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 486,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 486,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 485,
                    "last-line": 494,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 495,
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 495,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 495,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "routePaths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 497,
                                    "char": 23
                                },
                                {
                                    "variable": "pcrePattern",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 497,
                                    "char": 36
                                },
                                {
                                    "variable": "compiledPattern",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 497,
                                    "char": 53
                                },
                                {
                                    "variable": "extracted",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 497,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 499,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "routePaths",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "getRoutePaths",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 499,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 499,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 499,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 499,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 504,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "starts_with",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 504,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 504,
                                            "char": 32
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "#",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 504,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 504,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 504,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 504,
                                "char": 37
                            },
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 505,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 505,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "{",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 505,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 505,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 505,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "extracted",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 509,
                                                            "char": 38
                                                        },
                                                        "name": "extractNamedParams",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 509,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 509,
                                                                "char": 65
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 509,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 509,
                                                    "char": 66
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pcrePattern",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "extracted",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 510,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 510,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 510,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 510,
                                                    "char": 47
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "routePaths",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "routePaths",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 511,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 511,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "extracted",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 511,
                                                                        "char": 67
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                        "line": 511,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                    "line": 511,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                                "line": 511,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 511,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 511,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 512,
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
                                                    "variable": "pcrePattern",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "pattern",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 513,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 513,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 514,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 519,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "compiledPattern",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                    "line": 519,
                                                    "char": 40
                                                },
                                                "name": "compilePattern",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "pcrePattern",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                            "line": 519,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                        "line": 519,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 519,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 519,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 520,
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
                                            "variable": "compiledPattern",
                                            "expr": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                                "line": 521,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 521,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 522,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 527,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "pattern",
                                    "expr": {
                                        "type": "variable",
                                        "value": "pattern",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 527,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 527,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 532,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "compiledPattern",
                                    "expr": {
                                        "type": "variable",
                                        "value": "compiledPattern",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 532,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 532,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 537,
                            "char": 11
                        },
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
                                        "value": "routePaths",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 537,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 537,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 538,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reconfigure the route adding a new pattern and a set of paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 496,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 495,
                    "last-line": 542,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "reset",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "uniqueId",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 545,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 545,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 546,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets the internal route id generator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 544,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 543,
                    "last-line": 550,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setGroup",
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
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 551,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 551,
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
                                    "property": "group",
                                    "expr": {
                                        "type": "variable",
                                        "value": "group",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 553,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 553,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 555,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 555,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 556,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the group associated with the route\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 552,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 552,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 552,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 551,
                    "last-line": 571,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 572,
                            "char": 51
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
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 574,
                                    "char": 21
                                },
                                "name": "via",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "httpMethods",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                            "line": 574,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 574,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 574,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 575,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a set of HTTP methods that constraint the matching of the route (alias of via)\n     *\n     *```php\n     * $route->setHttpMethods(\"GET\");\n     *\n     * $route->setHttpMethods(\n     *     [\n     *         \"GET\",\n     *         \"POST\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 573,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 573,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 573,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 572,
                    "last-line": 583,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 584,
                            "char": 49
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
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 586,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 586,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 588,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 588,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 589,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a hostname restriction to the route\n     *\n     *```php\n     * $route->setHostname(\"localhost\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 585,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 585,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 585,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 584,
                    "last-line": 602,
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 603,
                            "char": 40
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
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 605,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 605,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 607,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 607,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 608,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the route's name\n     *\n     *```php\n     * $router->add(\n     *     \"\/about\",\n     *     [\n     *         \"controller\" => \"about\",\n     *     ]\n     * )->setName(\"about\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 604,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 604,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 604,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 603,
                    "last-line": 623,
                    "char": 19
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
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 624,
                            "char": 40
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
                                    "property": "methods",
                                    "expr": {
                                        "type": "variable",
                                        "value": "httpMethods",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                        "line": 626,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 626,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 628,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 628,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                            "line": 629,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set one or more HTTP methods that constraint the matching of the route\n     *\n     *```php\n     * $route->via(\"GET\");\n     *\n     * $route->via(\n     *     [\n     *         \"GET\",\n     *         \"POST\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                    "line": 625,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                                "line": 625,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                        "line": 625,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
                    "line": 624,
                    "last-line": 630,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Router\/Route.zep",
        "line": 20,
        "char": 5
    }
]