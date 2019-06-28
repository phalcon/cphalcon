[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cli\\Router",
        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class represents every route added to the router\n *",
        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Route",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "beforeMatch",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 22,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "compiledPattern",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 24,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "converters",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 26,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "delimiter",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 28,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "delimiterPath",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "self",
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 28,
                            "char": 61
                        },
                        "right": {
                            "type": "variable",
                            "value": "DEFAULT_DELIMITER",
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 28,
                            "char": 61
                        },
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 28,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 30,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "description",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 32,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "id",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 34,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 36,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "paths",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 38,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "pattern",
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 40,
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
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 40,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 44,
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
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 45,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 45,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 45,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "routeId",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 47,
                                    "char": 20
                                },
                                {
                                    "variable": "uniqueId",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 47,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 50,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "delimiter",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 50,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "delimiterPath",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 50,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 50,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 50,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 53,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 53,
                                    "char": 14
                                },
                                "name": "reConfigure",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 53,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 53,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paths",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 53,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 53,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 53,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 56,
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
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 56,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "uniqueId",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 56,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 56,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 56,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 59,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 59,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 59,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 60,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 60,
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
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 61,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 61,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 61,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 61,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 62,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param array|string paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 46,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 45,
                    "last-line": 70,
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
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 71,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 73,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 73,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 75,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 75,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 76,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a callback that is called if the route is matched.\n     * The developer can implement any arbitrary conditions here\n     * If the callback returns false the route is treated as not matched\n     *\n     * @param callback callback\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 72,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 72,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 71,
                    "last-line": 81,
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
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 82,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "idPattern",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 84,
                                    "char": 22
                                },
                                {
                                    "variable": "part",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 84,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 87,
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
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 87,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 87,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": ":",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 87,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 87,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 87,
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
                                                "type": "concat",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 90,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "delimiter",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 90,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 90,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "([a-zA-Z0-9\\\\_\\\\-]+)",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 90,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 90,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 90,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 93,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 93,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 93,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ":delimiter",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 93,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 93,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 93,
                                        "char": 44
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
                                                                    "value": ":delimiter",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 95,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 95,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 96,
                                                                        "char": 26
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "delimiter",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 96,
                                                                        "char": 36
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 96,
                                                                    "char": 36
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 96,
                                                                "char": 36
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 98,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 98,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 98,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 98,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 99,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 102,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "part",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 102,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "delimiter",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 102,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 102,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ":module",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 102,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 102,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 102,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 103,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 103,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 103,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 103,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 103,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 103,
                                        "char": 38
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
                                                                    "type": "variable",
                                                                    "value": "part",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 104,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 104,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 104,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 104,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 104,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 104,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 104,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 104,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 105,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 108,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "part",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 108,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "delimiter",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 108,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 108,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ":task",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 108,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 108,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 108,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 109,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 109,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 109,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 109,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 109,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 109,
                                        "char": 38
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
                                                                    "type": "variable",
                                                                    "value": "part",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 110,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 110,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 110,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 110,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 110,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 110,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 110,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 110,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 111,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 114,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "part",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 114,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "delimiter",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 114,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 114,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ":namespace",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 114,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 114,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 114,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 115,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 115,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 115,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 115,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 115,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 115,
                                        "char": 38
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
                                                                    "type": "variable",
                                                                    "value": "part",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 116,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 116,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 116,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 116,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 116,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 116,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 116,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 116,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 117,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 120,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "part",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 120,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "delimiter",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 120,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 120,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ":action",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 120,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 120,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 120,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 121,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 121,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 121,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 121,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 121,
                                        "char": 38
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
                                                                    "type": "variable",
                                                                    "value": "part",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 122,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 122,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "idPattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 122,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 122,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 122,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 122,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 122,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 122,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 123,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 126,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "part",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 126,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "delimiter",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 126,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 126,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ":params",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 126,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 126,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 126,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 127,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 127,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 127,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 127,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 127,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 127,
                                        "char": 38
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
                                                                    "type": "variable",
                                                                    "value": "part",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 129,
                                                                    "char": 25
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 129,
                                                                "char": 25
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "(",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 130,
                                                                            "char": 23
                                                                        },
                                                                        "right": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                "line": 130,
                                                                                "char": 30
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "delimiter",
                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                "line": 130,
                                                                                "char": 41
                                                                            },
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 130,
                                                                            "char": 41
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 130,
                                                                        "char": 41
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": ".*)*",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 130,
                                                                        "char": 47
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 130,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 130,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 132,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 132,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 132,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 132,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 133,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 136,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "part",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 136,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "delimiter",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 136,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 136,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ":int",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 136,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 136,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 136,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 137,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 137,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 137,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 137,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 137,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 137,
                                        "char": 38
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
                                                                    "type": "variable",
                                                                    "value": "part",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 139,
                                                                    "char": 25
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 139,
                                                                "char": 25
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 140,
                                                                            "char": 26
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "delimiter",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 140,
                                                                            "char": 37
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 140,
                                                                        "char": 37
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "([0-9]+)",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 140,
                                                                        "char": 47
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 140,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 140,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 142,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 142,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 142,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 142,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 143,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 144,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 150,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 150,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 150,
                                            "char": 26
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "(",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 150,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 150,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 150,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 150,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 150,
                                            "char": 48
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "[",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 150,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 150,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 150,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 150,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 151,
                                                "char": 23
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 151,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 151,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "$#",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 151,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 151,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 152,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 154,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "pattern",
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 154,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 155,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 83,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 83,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 82,
                    "last-line": 162,
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
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 163,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "converter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 163,
                            "char": 52
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
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 165,
                                            "char": 34
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "converter",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 165,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 165,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 167,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 167,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 168,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a converter to perform an additional transformation for certain\n     * parameter\n     *\n     * @param callable converter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RouteInterface",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 164,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 164,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 164,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 163,
                    "last-line": 172,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 173,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 173,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "delimiterPath",
                                    "expr": {
                                        "type": "variable",
                                        "value": "delimiter",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 175,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 175,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 176,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the routing delimiter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 174,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 173,
                    "last-line": 180,
                    "char": 26
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
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 181,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 183,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 184,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "tmp",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 184,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 185,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 185,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 186,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "notValid",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 186,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 187,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "cursor",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 187,
                                    "char": 19
                                },
                                {
                                    "variable": "cursorVar",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 187,
                                    "char": 30
                                },
                                {
                                    "variable": "marker",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 187,
                                    "char": 38
                                },
                                {
                                    "variable": "bracketCount",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 187,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 187,
                                    "char": 56
                                },
                                {
                                    "variable": "parenthesesCount",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 187,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 187,
                                    "char": 78
                                },
                                {
                                    "variable": "foundPattern",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 187,
                                        "char": 96
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 187,
                                    "char": 96
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 188,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 188,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 188,
                                    "char": 29
                                },
                                {
                                    "variable": "numberMatches",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 188,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 188,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 189,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 189,
                                    "char": 21
                                },
                                {
                                    "variable": "item",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 189,
                                    "char": 27
                                },
                                {
                                    "variable": "variable",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 189,
                                    "char": 37
                                },
                                {
                                    "variable": "regexp",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 189,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 191,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 191,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 191,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 191,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 191,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 191,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 192,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 193,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 195,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 195,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 195,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "route",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 196,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 196,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "pattern",
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 198,
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
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 199,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 199,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 199,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 200,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "char",
                                                    "value": "{",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 200,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 200,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 201,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 201,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 201,
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
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 202,
                                                                            "char": 45
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "1",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 202,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 202,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 202,
                                                                    "char": 48
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "intermediate",
                                                                    "expr": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 203,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 203,
                                                                    "char": 45
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "notValid",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 204,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 204,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 205,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 207,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "incr",
                                                            "variable": "bracketCount",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 207,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 208,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 208,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "char",
                                                            "value": "}",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 208,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 208,
                                                        "char": 35
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "bracketCount",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 209,
                                                                    "char": 39
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 211,
                                                            "char": 22
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "greater",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "intermediate",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 211,
                                                                    "char": 37
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 211,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 211,
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
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 212,
                                                                            "char": 42
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "0",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 212,
                                                                            "char": 46
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 212,
                                                                        "char": 46
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "incr",
                                                                                    "variable": "numberMatches",
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 213,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "variable",
                                                                                    "expr": {
                                                                                        "type": "null",
                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                        "line": 214,
                                                                                        "char": 48
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 214,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "regexp",
                                                                                    "expr": {
                                                                                        "type": "null",
                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                        "line": 215,
                                                                                        "char": 46
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 215,
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
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 216,
                                                                                                        "char": 63
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 216,
                                                                                                    "char": 63
                                                                                                },
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "variable",
                                                                                                        "value": "marker",
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 216,
                                                                                                        "char": 71
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 216,
                                                                                                    "char": 71
                                                                                                },
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "sub",
                                                                                                        "left": {
                                                                                                            "type": "variable",
                                                                                                            "value": "cursor",
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 216,
                                                                                                            "char": 80
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "variable",
                                                                                                            "value": "marker",
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 216,
                                                                                                            "char": 88
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 216,
                                                                                                        "char": 88
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 216,
                                                                                                    "char": 88
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 216,
                                                                                            "char": 89
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                        "line": 216,
                                                                                        "char": 89
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 216,
                                                                                    "char": 89
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 218,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "type": "for",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "item",
                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                "line": 218,
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
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 219,
                                                                                            "char": 40
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "char",
                                                                                            "value": "\\0",
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 219,
                                                                                            "char": 46
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                        "line": 219,
                                                                                        "char": 46
                                                                                    },
                                                                                    "statements": [
                                                                                        {
                                                                                            "type": "break",
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 221,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 223,
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
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 223,
                                                                                                "char": 47
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "int",
                                                                                                "value": "0",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 223,
                                                                                                "char": 52
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 223,
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
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 60
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "a",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 66
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 223,
                                                                                                                "char": 66
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "less-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 71
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "z",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 75
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 223,
                                                                                                                "char": 75
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 223,
                                                                                                            "char": 75
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 223,
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
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 84
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "A",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 90
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 223,
                                                                                                                "char": 90
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "less-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 95
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "Z",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 223,
                                                                                                                    "char": 99
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 223,
                                                                                                                "char": 99
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 223,
                                                                                                            "char": 99
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 223,
                                                                                                        "char": 100
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 223,
                                                                                                    "char": 100
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 223,
                                                                                                "char": 102
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 223,
                                                                                            "char": 102
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                        "line": 223,
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
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 224,
                                                                                                        "char": 56
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 224,
                                                                                                    "char": 56
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 226,
                                                                                            "char": 41
                                                                                        },
                                                                                        {
                                                                                            "type": "break",
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 227,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 229,
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
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 40
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "a",
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 46
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 46
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "less-equal",
                                                                                                                    "left": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "ch",
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 51
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "z",
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 55
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 55
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 229,
                                                                                                                "char": 55
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 229,
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
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 64
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "A",
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 70
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 70
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "less-equal",
                                                                                                                    "left": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "ch",
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 75
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "char",
                                                                                                                        "value": "Z",
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 229,
                                                                                                                        "char": 79
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 79
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 229,
                                                                                                                "char": 79
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 229,
                                                                                                            "char": 82
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 229,
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
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 88
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "0",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 94
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 229,
                                                                                                                "char": 94
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "less-equal",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "ch",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 99
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "9",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 229,
                                                                                                                    "char": 102
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 229,
                                                                                                                "char": 102
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 229,
                                                                                                            "char": 102
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 229,
                                                                                                        "char": 105
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 229,
                                                                                                    "char": 105
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "equals",
                                                                                                    "left": {
                                                                                                        "type": "variable",
                                                                                                        "value": "ch",
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 229,
                                                                                                        "char": 111
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "char",
                                                                                                        "value": "-",
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 229,
                                                                                                        "char": 117
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 229,
                                                                                                    "char": 117
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 229,
                                                                                                "char": 117
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "equals",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "ch",
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 229,
                                                                                                    "char": 123
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "char",
                                                                                                    "value": "_",
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 229,
                                                                                                    "char": 129
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 229,
                                                                                                "char": 129
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 229,
                                                                                            "char": 129
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "equals",
                                                                                            "left": {
                                                                                                "type": "variable",
                                                                                                "value": "ch",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 229,
                                                                                                "char": 135
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "char",
                                                                                                "value": ":",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 229,
                                                                                                "char": 141
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 229,
                                                                                            "char": 141
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                        "line": 229,
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
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 230,
                                                                                                    "char": 44
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "char",
                                                                                                    "value": ":",
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 230,
                                                                                                    "char": 49
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 230,
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
                                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                "line": 231,
                                                                                                                                "char": 76
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                            "line": 231,
                                                                                                                            "char": 76
                                                                                                                        },
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "int",
                                                                                                                                "value": "0",
                                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                "line": 231,
                                                                                                                                "char": 79
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                            "line": 231,
                                                                                                                            "char": 79
                                                                                                                        },
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "variable",
                                                                                                                                "value": "cursorVar",
                                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                "line": 231,
                                                                                                                                "char": 90
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                            "line": 231,
                                                                                                                            "char": 90
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 231,
                                                                                                                    "char": 91
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 231,
                                                                                                                "char": 91
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 231,
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
                                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                "line": 232,
                                                                                                                                "char": 74
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                            "line": 232,
                                                                                                                            "char": 74
                                                                                                                        },
                                                                                                                        {
                                                                                                                            "parameter": {
                                                                                                                                "type": "add",
                                                                                                                                "left": {
                                                                                                                                    "type": "variable",
                                                                                                                                    "value": "cursorVar",
                                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                    "line": 232,
                                                                                                                                    "char": 86
                                                                                                                                },
                                                                                                                                "right": {
                                                                                                                                    "type": "int",
                                                                                                                                    "value": "1",
                                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                    "line": 232,
                                                                                                                                    "char": 89
                                                                                                                                },
                                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                "line": 232,
                                                                                                                                "char": 89
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                            "line": 232,
                                                                                                                            "char": 89
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 232,
                                                                                                                    "char": 90
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 232,
                                                                                                                "char": 90
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 232,
                                                                                                            "char": 90
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 234,
                                                                                                    "char": 45
                                                                                                },
                                                                                                {
                                                                                                    "type": "break",
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 235,
                                                                                                    "char": 37
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 236,
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
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 237,
                                                                                                        "char": 56
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 237,
                                                                                                    "char": 56
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 239,
                                                                                            "char": 41
                                                                                        },
                                                                                        {
                                                                                            "type": "break",
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 240,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 241,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 243,
                                                                            "char": 30
                                                                        },
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "not",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "notValid",
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 243,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                "line": 243,
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
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 244,
                                                                                                "char": 56
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 244,
                                                                                            "char": 56
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 246,
                                                                                    "char": 34
                                                                                },
                                                                                {
                                                                                    "type": "if",
                                                                                    "expr": {
                                                                                        "type": "and",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "variable",
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 246,
                                                                                            "char": 46
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "regexp",
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 246,
                                                                                            "char": 55
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                        "line": 246,
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
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 247,
                                                                                                        "char": 57
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 247,
                                                                                                    "char": 57
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 249,
                                                                                            "char": 39
                                                                                        },
                                                                                        {
                                                                                            "type": "for",
                                                                                            "expr": {
                                                                                                "type": "variable",
                                                                                                "value": "regexp",
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 249,
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
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 250,
                                                                                                            "char": 48
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "char",
                                                                                                            "value": "\\0",
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 250,
                                                                                                            "char": 54
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 250,
                                                                                                        "char": 54
                                                                                                    },
                                                                                                    "statements": [
                                                                                                        {
                                                                                                            "type": "break",
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 252,
                                                                                                            "char": 41
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 254,
                                                                                                    "char": 42
                                                                                                },
                                                                                                {
                                                                                                    "type": "if",
                                                                                                    "expr": {
                                                                                                        "type": "not",
                                                                                                        "left": {
                                                                                                            "type": "variable",
                                                                                                            "value": "foundPattern",
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 254,
                                                                                                            "char": 58
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 254,
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
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 255,
                                                                                                                    "char": 52
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": "(",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 255,
                                                                                                                    "char": 57
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 255,
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
                                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                "line": 256,
                                                                                                                                "char": 69
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                            "line": 256,
                                                                                                                            "char": 69
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 257,
                                                                                                                    "char": 45
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 258,
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
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 259,
                                                                                                                    "char": 52
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "char",
                                                                                                                    "value": ")",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 259,
                                                                                                                    "char": 57
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 259,
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
                                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                                "line": 260,
                                                                                                                                "char": 69
                                                                                                                            },
                                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                            "line": 260,
                                                                                                                            "char": 69
                                                                                                                        }
                                                                                                                    ],
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 262,
                                                                                                                    "char": 53
                                                                                                                },
                                                                                                                {
                                                                                                                    "type": "break",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 263,
                                                                                                                    "char": 45
                                                                                                                }
                                                                                                            ],
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 264,
                                                                                                            "char": 41
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 265,
                                                                                                    "char": 38
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 267,
                                                                                            "char": 38
                                                                                        },
                                                                                        {
                                                                                            "type": "if",
                                                                                            "expr": {
                                                                                                "type": "not-equals",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "foundPattern",
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 267,
                                                                                                    "char": 54
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "int",
                                                                                                    "value": "2",
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 267,
                                                                                                    "char": 58
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 267,
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
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 268,
                                                                                                                        "char": 55
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "variable",
                                                                                                                        "value": "regexp",
                                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                        "line": 268,
                                                                                                                        "char": 64
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 268,
                                                                                                                    "char": 64
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "string",
                                                                                                                    "value": ")",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 268,
                                                                                                                    "char": 67
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 268,
                                                                                                                "char": 67
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 268,
                                                                                                            "char": 67
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 269,
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
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 270,
                                                                                                                "char": 59
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 270,
                                                                                                            "char": 59
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 271,
                                                                                                    "char": 37
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 273,
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
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 273,
                                                                                                            "char": 57
                                                                                                        }
                                                                                                    ],
                                                                                                    "expr": {
                                                                                                        "type": "variable",
                                                                                                        "value": "tmp",
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 273,
                                                                                                        "char": 64
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 273,
                                                                                                    "char": 64
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 274,
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
                                                                                                        "type": "concat",
                                                                                                        "left": {
                                                                                                            "type": "concat",
                                                                                                            "left": {
                                                                                                                "type": "string",
                                                                                                                "value": "([^",
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 275,
                                                                                                                "char": 53
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "property-access",
                                                                                                                "left": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "this",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 275,
                                                                                                                    "char": 60
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "delimiter",
                                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                    "line": 275,
                                                                                                                    "char": 71
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                                "line": 275,
                                                                                                                "char": 71
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 275,
                                                                                                            "char": 71
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "string",
                                                                                                            "value": "]*)",
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 275,
                                                                                                            "char": 76
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 275,
                                                                                                        "char": 76
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 275,
                                                                                                    "char": 76
                                                                                                },
                                                                                                {
                                                                                                    "assign-type": "array-index",
                                                                                                    "operator": "assign",
                                                                                                    "variable": "matches",
                                                                                                    "index-expr": [
                                                                                                        {
                                                                                                            "type": "variable",
                                                                                                            "value": "item",
                                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                            "line": 276,
                                                                                                            "char": 53
                                                                                                        }
                                                                                                    ],
                                                                                                    "expr": {
                                                                                                        "type": "variable",
                                                                                                        "value": "tmp",
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 276,
                                                                                                        "char": 60
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 276,
                                                                                                    "char": 60
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 277,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 278,
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
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 279,
                                                                                                        "char": 47
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "variable",
                                                                                                        "value": "item",
                                                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                        "line": 279,
                                                                                                        "char": 54
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 279,
                                                                                                    "char": 54
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "string",
                                                                                                    "value": "}",
                                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                    "line": 279,
                                                                                                    "char": 57
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                                "line": 279,
                                                                                                "char": 57
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                            "line": 279,
                                                                                            "char": 57
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                                    "line": 280,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 282,
                                                                            "char": 36
                                                                        },
                                                                        {
                                                                            "type": "continue",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 283,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 284,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 285,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 286,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 286,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 288,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "bracketCount",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 288,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 288,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 288,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 289,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "char",
                                                    "value": "(",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 289,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 289,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "incr",
                                                            "variable": "parenthesesCount",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 290,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 291,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 291,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "char",
                                                            "value": ")",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 291,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 291,
                                                        "char": 35
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "parenthesesCount",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 292,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 294,
                                                            "char": 22
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parenthesesCount",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 294,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 294,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 294,
                                                                "char": 46
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "incr",
                                                                            "variable": "numberMatches",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 295,
                                                                            "char": 44
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 296,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 297,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 298,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 298,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 300,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "bracketCount",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 300,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 300,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 300,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "incr",
                                                    "variable": "intermediate",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 301,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 302,
                                            "char": 13
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
                                                        "value": "ch",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 303,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 303,
                                                    "char": 31
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 304,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 305,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 307,
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
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 307,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 307,
                                        "char": 22
                                    },
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "matches",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 307,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 307,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 307,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 308,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 181,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 182,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 182,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 181,
                    "last-line": 312,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 315,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "beforeMatch",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 315,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 315,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 316,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the 'before match' callback if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 314,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 314,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 313,
                    "last-line": 320,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 323,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "compiledPattern",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 323,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 323,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 324,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 322,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 322,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 321,
                    "last-line": 328,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 331,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "converters",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 331,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 331,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 332,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 330,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 330,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 329,
                    "last-line": 336,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getDelimiter",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 339,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "delimiterPath",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 339,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 339,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 340,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get routing delimiter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 338,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 338,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 337,
                    "last-line": 344,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDescription",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 347,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "description",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 347,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 347,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 348,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the route's description\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 346,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 346,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 345,
                    "last-line": 352,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 355,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 355,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 355,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 356,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 354,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 354,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 353,
                    "last-line": 360,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 363,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "paths",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 363,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 363,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 364,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 362,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 362,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 361,
                    "last-line": 368,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 371,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "pattern",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 371,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 371,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 372,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 370,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 370,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 369,
                    "last-line": 376,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 380,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "paths",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 381,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 381,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 381,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 381,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 382,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 378,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 378,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 377,
                    "last-line": 386,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 389,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "id",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 389,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 389,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 390,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 388,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 388,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 387,
                    "last-line": 396,
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
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 397,
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
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 397,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 397,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "moduleName",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 399,
                                    "char": 23
                                },
                                {
                                    "variable": "taskName",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 399,
                                    "char": 33
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 399,
                                    "char": 45
                                },
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 399,
                                    "char": 52
                                },
                                {
                                    "variable": "routePaths",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 399,
                                    "char": 64
                                },
                                {
                                    "variable": "realClassName",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 399,
                                    "char": 79
                                },
                                {
                                    "variable": "namespaceName",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 400,
                                    "char": 26
                                },
                                {
                                    "variable": "pcrePattern",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 400,
                                    "char": 39
                                },
                                {
                                    "variable": "compiledPattern",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 400,
                                    "char": 56
                                },
                                {
                                    "variable": "extracted",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 400,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 402,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "paths",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 402,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 402,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 402,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 403,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 403,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 404,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 406,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 406,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 406,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 406,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 406,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 407,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 407,
                                            "char": 34
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "taskName",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 408,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 408,
                                            "char": 32
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "actionName",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 409,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 409,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 412,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 412,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 412,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "paths",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 412,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 412,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 412,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 412,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 415,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 415,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 415,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 415,
                                        "char": 33
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "3",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
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
                                                            "variable": "moduleName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 418,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 418,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 418,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 418,
                                                            "char": 46
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "taskName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 419,
                                                                    "char": 41
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 419,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 419,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 419,
                                                            "char": 44
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
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 420,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "2",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 420,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 420,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 420,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 421,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 423,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 423,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 423,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "taskName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 424,
                                                                    "char": 41
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 424,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 424,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 424,
                                                            "char": 44
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
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 425,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 425,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 425,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 425,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 426,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 428,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 428,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 428,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "taskName",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parts",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 429,
                                                                    "char": 41
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 429,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 429,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 429,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 430,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 431,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 431,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 433,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 433,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 433,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 436,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "moduleName",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 436,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 436,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 436,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 437,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "moduleName",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 437,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 437,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 438,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 441,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "taskName",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 441,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 441,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 441,
                                        "char": 34
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
                                                            "value": "taskName",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 443,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 443,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\\\\",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 443,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 443,
                                                        "char": 39
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 443,
                                                "char": 41
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
                                                                            "value": "taskName",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 445,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 445,
                                                                        "char": 62
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 445,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 445,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 448,
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
                                                                            "value": "taskName",
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 448,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 448,
                                                                        "char": 62
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 448,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 448,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 450,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "list",
                                                            "left": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "namespaceName",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 450,
                                                                        "char": 50
                                                                    },
                                                                    "right": {
                                                                        "type": "null",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 450,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 450,
                                                                    "char": 58
                                                                },
                                                                "right": {
                                                                    "type": "identical",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "realClassName",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 450,
                                                                        "char": 76
                                                                    },
                                                                    "right": {
                                                                        "type": "null",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 450,
                                                                        "char": 82
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 450,
                                                                    "char": 82
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 450,
                                                                "char": 82
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 450,
                                                            "char": 84
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 450,
                                                        "char": 84
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
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 453,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 453,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 453,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 454,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 457,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "namespaceName",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 457,
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
                                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                            "line": 458,
                                                                            "char": 49
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "namespaceName",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 458,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 458,
                                                                    "char": 66
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 459,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 460,
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
                                                                "value": "taskName",
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 461,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 461,
                                                            "char": 49
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 462,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 465,
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
                                                            "value": "task",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 465,
                                                            "char": 36
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
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 465,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 465,
                                                                "char": 64
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 465,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 465,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 466,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 469,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "actionName",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 469,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 469,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 469,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 470,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "actionName",
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 470,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 470,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 471,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 472,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 473,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 473,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 474,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 476,
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
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 476,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 476,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 476,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 476,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 476,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 477,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 477,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 477,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 478,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 484,
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
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 484,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 484,
                                            "char": 32
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "#",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 484,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 484,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 484,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 484,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 485,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 485,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "{",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 485,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 485,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 485,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 489,
                                                            "char": 38
                                                        },
                                                        "name": "extractNamedParams",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 489,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 489,
                                                                "char": 65
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 489,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 489,
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
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 490,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 490,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 490,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 490,
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
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 491,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 491,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "extracted",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 491,
                                                                        "char": 67
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 491,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 491,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 491,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 491,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 491,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 492,
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
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 493,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 493,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 494,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 499,
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 499,
                                                    "char": 40
                                                },
                                                "name": "compilePattern",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "pcrePattern",
                                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                            "line": 499,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 499,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 499,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 499,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 500,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
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
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 502,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 502,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ":delimiter",
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 502,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 502,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 502,
                                        "char": 44
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
                                                                    "value": ":delimiter",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 504,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 504,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 505,
                                                                        "char": 26
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "delimiter",
                                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                        "line": 505,
                                                                        "char": 36
                                                                    },
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 505,
                                                                    "char": 36
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 505,
                                                                "char": 36
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "pattern",
                                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                    "line": 507,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                                "line": 507,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                        "line": 507,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                    "line": 507,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 508,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 510,
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
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                                "line": 510,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                            "line": 510,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 511,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 516,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 516,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 516,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 521,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 521,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 521,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 526,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 526,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 526,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 527,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reconfigure the route adding a new pattern and a set of paths\n     *\n     * @param array|string paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 398,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 397,
                    "last-line": 531,
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 534,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 534,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 535,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets the internal route id generator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 533,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 532,
                    "last-line": 539,
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
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 540,
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
                                    "property": "description",
                                    "expr": {
                                        "type": "variable",
                                        "value": "description",
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 542,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 542,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 544,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 544,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 545,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 541,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 541,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 541,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 540,
                    "last-line": 558,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 559,
                            "char": 41
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
                                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                        "line": 561,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 561,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 563,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 563,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                            "line": 564,
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
                                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                    "line": 560,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                                "line": 560,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 560,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 559,
                    "last-line": 565,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "DEFAULT_DELIMITER",
                    "default": {
                        "type": "string",
                        "value": " ",
                        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                        "line": 18,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
                    "line": 20,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Cli\/Router\/Route.zep",
        "line": 16,
        "char": 5
    }
]