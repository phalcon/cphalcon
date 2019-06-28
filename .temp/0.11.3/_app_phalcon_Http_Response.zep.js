[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http",
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "DateTime",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 13,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "DateTimeZone",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 14,
                "char": 17
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 15,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 16,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\Exception",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 17,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\HeadersInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 18,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\CookiesInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 19,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\UrlInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 20,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ViewInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 21,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\Headers",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 22,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 23,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 24,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 25,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 25,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 40,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Part of the HTTP cycle is return responses to the clients.\n * Phalcon\\HTTP\\Response is the Phalcon component responsible to achieve this task.\n * HTTP responses are usually composed by headers and body.\n *\n *```php\n * $response = new \\Phalcon\\Http\\Response();\n *\n * $response->setStatusCode(200, \"OK\");\n * $response->setContent(\"<html><body>Hello<\/body><\/html>\");\n *\n * $response->send();\n *```\n *",
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 41,
        "char": 5
    },
    {
        "type": "class",
        "name": "Response",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ResponseInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 41,
                "char": 44
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 41,
                "char": 69
            },
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Http\/Response.zep",
                "line": 42,
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
                    "name": "container",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 45,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "content",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 47,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "cookies",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 49,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 51,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "file",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 53,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "headers",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 57,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sent",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 58,
                        "char": 27
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 60,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "statusCodes",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 64,
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
                            "name": "content",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 65,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 65,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 65,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 65,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "status",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 65,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 65,
                            "char": 75
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
                                    "property": "headers",
                                    "expr": {
                                        "type": "new",
                                        "class": "Headers",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 70,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 70,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 72,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "content",
                                    "expr": {
                                        "type": "variable",
                                        "value": "content",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 72,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 72,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 74,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "code",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 74,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 74,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 74,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 75,
                                            "char": 18
                                        },
                                        "name": "setStatusCode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "code",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 75,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 75,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "status",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 75,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 75,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 75,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 77,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Http\\Response constructor\n     *",
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 65,
                    "last-line": 81,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "appendContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 82,
                            "char": 42
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
                                    "property": "content",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 84,
                                                "char": 34
                                            },
                                            "name": "getContent",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 84,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 84,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 84,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 84,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 86,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 86,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 87,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Appends a string to the HTTP response body\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 83,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 83,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 83,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 82,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContent",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 94,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "content",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 94,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 94,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the HTTP response body\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 93,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 92,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCookies",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 102,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "cookies",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 102,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 102,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns cookies set by the user\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookiesInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 101,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 101,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 100,
                    "last-line": 107,
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
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 110,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 112,
                            "char": 11
                        },
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
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 112,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 112,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 112,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 112,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 112,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 112,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 114,
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 114,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 114,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 114,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 114,
                                "char": 39
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
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Di",
                                                "dynamic": 0,
                                                "name": "getDefault",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 115,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 115,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 117,
                                    "char": 14
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
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 117,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 117,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 117,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 117,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 117,
                                        "char": 52
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
                                                                        "value": "the 'url' service",
                                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                        "line": 119,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                    "line": 119,
                                                                    "char": 74
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 120,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 120,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 120,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 121,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 123,
                                    "char": 15
                                },
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
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 123,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 123,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 124,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 126,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "container",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 126,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 127,
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
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 109,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 108,
                    "last-line": 131,
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
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 134,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 134,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 134,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 135,
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
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 133,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 133,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 133,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 132,
                    "last-line": 139,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHeaders",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 142,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 142,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 142,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns headers set by the user\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "HeadersInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 141,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 141,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 140,
                    "last-line": 151,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReasonPhrase",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "statusReasonPhrase",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 154,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 156,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "statusReasonPhrase",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 157,
                                                            "char": 18
                                                        },
                                                        "name": "getHeaders",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 157,
                                                        "char": 32
                                                    },
                                                    "name": "get",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Status",
                                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                "line": 157,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 157,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 157,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 157,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 159,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 159,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 159,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 159,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 161,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "ternary",
                                "left": {
                                    "type": "variable",
                                    "value": "statusReasonPhrase",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 161,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "statusReasonPhrase",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 161,
                                    "char": 56
                                },
                                "extra": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 161,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 161,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 162,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the reason phrase\n     *\n     *```php\n     * echo $response->getReasonPhrase();\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 152,
                                "char": 49
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 153,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 153,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 152,
                    "last-line": 170,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStatusCode",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "statusCode",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 173,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 175,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "statusCode",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 176,
                                                            "char": 18
                                                        },
                                                        "name": "getHeaders",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 176,
                                                        "char": 32
                                                    },
                                                    "name": "get",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Status",
                                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                "line": 176,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 176,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 176,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 176,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 177,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 177,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "3",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 179,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 179,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 179,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 179,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 181,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "ternary",
                                "left": {
                                    "type": "variable",
                                    "value": "statusCode",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 181,
                                    "char": 27
                                },
                                "right": {
                                    "type": "cast",
                                    "left": "int",
                                    "right": {
                                        "type": "variable",
                                        "value": "statusCode",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 181,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 181,
                                    "char": 46
                                },
                                "extra": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 181,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 181,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 182,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the status code\n     *\n     *```php\n     * echo $response->getStatusCode();\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 171,
                                "char": 44
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 172,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 172,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 171,
                    "last-line": 190,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 191,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 193,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 195,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 195,
                                            "char": 28
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 195,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 195,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 197,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 197,
                                    "char": 24
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 197,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 197,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 197,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 198,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a header exists\n     *\n     *```php\n     * $response->hasHeader(\"Content-Type\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 192,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 192,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 191,
                    "last-line": 202,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isSent",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 205,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "sent",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 205,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 205,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 206,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the response is already sent\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 204,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 204,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 203,
                    "last-line": 226,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "redirect",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "location",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 227,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 227,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "externalRedirect",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 227,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 227,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "statusCode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "302",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 227,
                                "char": 98
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 227,
                            "char": 98
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "header",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 229,
                                    "char": 19
                                },
                                {
                                    "variable": "url",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 229,
                                    "char": 24
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 229,
                                    "char": 35
                                },
                                {
                                    "variable": "matched",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 229,
                                    "char": 44
                                },
                                {
                                    "variable": "view",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 229,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 231,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "location",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 231,
                                    "char": 22
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 231,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "location",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 232,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 232,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 233,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 235,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "externalRedirect",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 235,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "header",
                                            "expr": {
                                                "type": "variable",
                                                "value": "location",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 236,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 236,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 237,
                                    "char": 9
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
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "location",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 238,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 238,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 238,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 238,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strstr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "location",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 238,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 238,
                                                    "char": 60
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": ":\/\/",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 238,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 238,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 238,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 238,
                                        "char": 67
                                    },
                                    "statements": [
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
                                                                    "type": "string",
                                                                    "value": "\/^[^:\\\\\/?#]++:\/",
                                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                    "line": 239,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                "line": 239,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "location",
                                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                    "line": 239,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                "line": 239,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 239,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 239,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 241,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "matched",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 241,
                                                "char": 28
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "header",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "location",
                                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                "line": 242,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 242,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 243,
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
                                                            "variable": "header",
                                                            "expr": {
                                                                "type": "null",
                                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                "line": 244,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 244,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 245,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 246,
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
                                                    "variable": "header",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 247,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 247,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 248,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 249,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 251,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 251,
                                            "char": 30
                                        },
                                        "name": "getDI",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 251,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 251,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 253,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "header",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 253,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 253,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "url",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "UrlInterface",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 254,
                                                    "char": 63
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 254,
                                                        "char": 48
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "url",
                                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                                "line": 254,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 254,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 254,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 254,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 254,
                                            "char": 63
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "header",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "url",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 255,
                                                    "char": 30
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "location",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 255,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 255,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 255,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 255,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 256,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 258,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 258,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "view",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 258,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 258,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 258,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "view",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 259,
                                                    "char": 34
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "view",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 259,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 259,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 259,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 259,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 261,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "view",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 261,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "ViewInterface",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 261,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 261,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "view",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 262,
                                                    "char": 22
                                                },
                                                "name": "disable",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 262,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 263,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 264,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 269,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "less",
                                    "left": {
                                        "type": "variable",
                                        "value": "statusCode",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 269,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "300",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 269,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 269,
                                    "char": 30
                                },
                                "right": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "statusCode",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 269,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "308",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 269,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 269,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 269,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "statusCode",
                                            "expr": {
                                                "type": "int",
                                                "value": "302",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 270,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 270,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 271,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 273,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 273,
                                    "char": 14
                                },
                                "name": "setStatusCode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "statusCode",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 273,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 273,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 273,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 278,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 278,
                                    "char": 14
                                },
                                "name": "setHeader",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Location",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 278,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 278,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "header",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 278,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 278,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 278,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 280,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 280,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 281,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Redirect by HTTP to another action or URL\n     *\n     *```php\n     * \/\/ Using a string redirect (internal\/external)\n     * $response->redirect(\"posts\/index\");\n     * $response->redirect(\"http:\/\/en.wikipedia.org\", true);\n     * $response->redirect(\"http:\/\/www.example.com\/new-location\", true, 301);\n     *\n     * \/\/ Making a redirection based on a named route\n     * $response->redirect(\n     *     [\n     *         \"for\"        => \"index-lang\",\n     *         \"lang\"       => \"jp\",\n     *         \"controller\" => \"index\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 228,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 228,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 228,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 227,
                    "last-line": 289,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "removeHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 290,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 292,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 294,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 294,
                                            "char": 28
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 294,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 294,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 296,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 296,
                                    "char": 17
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 296,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 296,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 296,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 298,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 298,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 299,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Remove a header in the response\n     *\n     *```php\n     * $response->removeHeader(\"Expires\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 291,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 291,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 291,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 290,
                    "last-line": 302,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "resetHeaders",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 305,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 307,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 307,
                                            "char": 28
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 307,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 307,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 309,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 309,
                                    "char": 17
                                },
                                "name": "reset",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 309,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 311,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 311,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 312,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets all the established headers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 304,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 304,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 304,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 303,
                    "last-line": 316,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "send",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 319,
                                    "char": 20
                                },
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 319,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 321,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 321,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "sent",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 321,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 321,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 321,
                                "char": 32
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
                                                    "value": "Response was already sent",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 322,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 322,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 322,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 323,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 325,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 325,
                                    "char": 14
                                },
                                "name": "sendHeaders",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 325,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 327,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 327,
                                    "char": 14
                                },
                                "name": "sendCookies",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 327,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 332,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "content",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 332,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 332,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 332,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 332,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 334,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "content",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 334,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 334,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 334,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "echo",
                                    "expressions": [
                                        {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 335,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 336,
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
                                            "variable": "file",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 337,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 337,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 337,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 337,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 339,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 339,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 339,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 339,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 339,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strlen",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "file",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 339,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 339,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 339,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 339,
                                        "char": 54
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "readfile",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 340,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 340,
                                                        "char": 30
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 340,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 341,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 342,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 344,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "sent",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 344,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 344,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 346,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 346,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 347,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prints out HTTP response to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 318,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 318,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 318,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 317,
                    "last-line": 351,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sendCookies",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cookies",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 354,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 356,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cookies",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 356,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cookies",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 356,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 356,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 356,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 358,
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
                                        "value": "cookies",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 358,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 358,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 358,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 358,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookies",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 359,
                                            "char": 21
                                        },
                                        "name": "send",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 359,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 360,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 362,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 362,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 363,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sends cookies to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 353,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 353,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 353,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 352,
                    "last-line": 367,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sendHeaders",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 370,
                                    "char": 20
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 370,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 372,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "HeadersInterface",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 372,
                                            "char": 60
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 372,
                                                "char": 47
                                            },
                                            "name": "getHeaders",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 372,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 372,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 372,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 373,
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
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "ManagerInterface",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 373,
                                            "char": 72
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 373,
                                                "char": 53
                                            },
                                            "name": "getEventsManager",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 373,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 373,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 373,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 375,
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
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 375,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 375,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 375,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 375,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 376,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "response:beforeSendHeaders",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 376,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 376,
                                                    "char": 62
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 376,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 376,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 376,
                                            "char": 72
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 376,
                                            "char": 80
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 376,
                                        "char": 80
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 377,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 378,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 379,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 384,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "headers",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 384,
                                        "char": 20
                                    },
                                    "name": "send",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 384,
                                    "char": 29
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 384,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 384,
                                        "char": 53
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 384,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 384,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 384,
                                "char": 62
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 385,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "response:afterSendHeaders",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 385,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 385,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 385,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 385,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 385,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 386,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 388,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 388,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 389,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sends headers to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 368,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 368,
                                "char": 58
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 369,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 369,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 368,
                    "last-line": 397,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "minutes",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 398,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "date",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 400,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 402,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "date",
                                    "expr": {
                                        "type": "new",
                                        "class": "DateTime",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 402,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 402,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 404,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "date",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 404,
                                    "char": 14
                                },
                                "name": "modify",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "+",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 405,
                                                    "char": 15
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "minutes",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 405,
                                                    "char": 25
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 405,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": " minutes",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 406,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 406,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 406,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 406,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 408,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 408,
                                    "char": 14
                                },
                                "name": "setExpires",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "date",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 408,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 408,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 408,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 410,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 410,
                                    "char": 14
                                },
                                "name": "setHeader",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Cache-Control",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 411,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 411,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "max-age=",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 412,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "list",
                                                "left": {
                                                    "type": "mul",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "minutes",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 412,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "60",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 412,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 412,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 413,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 413,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 413,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 413,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 415,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 415,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 416,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets Cache headers to use HTTP cache\n     *\n     *```php\n     * $this->response->setCache(60);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 399,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 399,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 399,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 398,
                    "last-line": 424,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 425,
                            "char": 46
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
                                    "property": "content",
                                    "expr": {
                                        "type": "variable",
                                        "value": "content",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 427,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 427,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 429,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 429,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 430,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets HTTP response body\n     *\n     *```php\n     * $response->setContent(\"<h1>Hello!<\/h1>\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 426,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 426,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 426,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 425,
                    "last-line": 438,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContentLength",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "contentLength",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 439,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 441,
                                    "char": 14
                                },
                                "name": "setHeader",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Content-Length",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 441,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 441,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "contentLength",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 441,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 441,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 441,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 443,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 443,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 444,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the response content-length\n     *\n     *```php\n     * $response->setContentLength(2048);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 440,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 440,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 440,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 439,
                    "last-line": 453,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContentType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "contentType",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 454,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "charset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 454,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 454,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "charset",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 456,
                                    "char": 22
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 456,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 456,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "contentType",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "; charset=",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 457,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "charset",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 457,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 457,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 457,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 458,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 460,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 460,
                                    "char": 14
                                },
                                "name": "setHeader",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Content-Type",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 460,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 460,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "contentType",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 460,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 460,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 460,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 462,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 462,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 463,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the response content-type mime, optionally the charset\n     *\n     *```php\n     * $response->setContentType(\"application\/pdf\");\n     * $response->setContentType(\"text\/plain\", \"UTF-8\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 455,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 455,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 455,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 454,
                    "last-line": 467,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCookies",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cookies",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "CookiesInterface",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 468,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 468,
                            "char": 58
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
                                    "property": "cookies",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cookies",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 470,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 470,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 472,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 472,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 473,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a cookies bag for the response externally\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 469,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 469,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 469,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 468,
                    "last-line": 477,
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
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 478,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 478,
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
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 480,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 480,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 481,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 479,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 478,
                    "last-line": 493,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEtag",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "etag",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 494,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 496,
                                    "char": 14
                                },
                                "name": "setHeader",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Etag",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 496,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 496,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "etag",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 496,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 496,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 496,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 498,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 498,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 499,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set a custom ETag\n     *\n     *```php\n     * $response->setEtag(\n     *     md5(\n     *         time()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 495,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 495,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 495,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 494,
                    "last-line": 509,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setExpires",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "datetime",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DateTime",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 510,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 510,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "date",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 512,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 514,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "date",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "datetime",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 514,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 514,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 514,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 520,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "date",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 520,
                                    "char": 14
                                },
                                "name": "setTimezone",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "DateTimeZone",
                                            "dynamic": 0,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "UTC",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 521,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 521,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 522,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 522,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 522,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 527,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 527,
                                    "char": 14
                                },
                                "name": "setHeader",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Expires",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 528,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 528,
                                        "char": 20
                                    },
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "date",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 529,
                                                    "char": 18
                                                },
                                                "name": "format",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "D, d M Y H:i:s",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 529,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 529,
                                                        "char": 40
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 529,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": " GMT",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 530,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 530,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 530,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 530,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 532,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 532,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 533,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an Expires header in the response that allows to use the HTTP cache\n     *\n     *```php\n     * $this->response->setExpires(\n     *     new DateTime()\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 511,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 511,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 511,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 510,
                    "last-line": 537,
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
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 538,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 538,
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
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 540,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 540,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 541,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 539,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 538,
                    "last-line": 545,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFileToSend",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 546,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "attachmentName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 546,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 546,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "attachment",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 546,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 546,
                            "char": 92
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "basePath",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 548,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 550,
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
                                        "value": "attachmentName",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 550,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 550,
                                    "char": 35
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 550,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 550,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "basePath",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "basename",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filePath",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 551,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 551,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 551,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 551,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 552,
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
                                            "variable": "basePath",
                                            "expr": {
                                                "type": "variable",
                                                "value": "attachmentName",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 553,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 553,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 554,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 556,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "attachment",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 556,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 557,
                                            "char": 18
                                        },
                                        "name": "setRawHeader",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Content-Description: File Transfer",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 557,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 557,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 557,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 558,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 558,
                                            "char": 18
                                        },
                                        "name": "setRawHeader",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Content-Type: application\/octet-stream",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 558,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 558,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 558,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 559,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 559,
                                            "char": 18
                                        },
                                        "name": "setRawHeader",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Content-Disposition: attachment; filename=",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 559,
                                                            "char": 75
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "basePath",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 559,
                                                            "char": 86
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 559,
                                                        "char": 86
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": ";",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 559,
                                                        "char": 89
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 559,
                                                    "char": 89
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 559,
                                                "char": 89
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 559,
                                        "char": 90
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 560,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 560,
                                            "char": 18
                                        },
                                        "name": "setRawHeader",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Content-Transfer-Encoding: binary",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 560,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 560,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 560,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 561,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 563,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "file",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filePath",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 563,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 563,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 565,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 565,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 566,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an attached file to be sent at the end of the request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 547,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 547,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 547,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 546,
                    "last-line": 574,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 575,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 575,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 577,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 579,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 579,
                                            "char": 28
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 579,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 579,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 581,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 581,
                                    "char": 17
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 581,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 581,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 581,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 581,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 581,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 583,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 583,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 584,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Overwrites a header in the response\n     *\n     *```php\n     * $response->setHeader(\"Content-Type\", \"text\/plain\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 576,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 576,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 576,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 575,
                    "last-line": 588,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHeaders",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "HeadersInterface",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 589,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 589,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 591,
                                    "char": 17
                                },
                                {
                                    "variable": "existing",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 591,
                                    "char": 27
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 591,
                                    "char": 33
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 591,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 593,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 593,
                                            "char": 28
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 593,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 593,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "existing",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 594,
                                            "char": 29
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 594,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 594,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 596,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 596,
                                "char": 33
                            },
                            "key": "name",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "existing",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 597,
                                            "char": 22
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 597,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 597,
                                                "char": 31
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 597,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 597,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 597,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 598,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 600,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "headers",
                                    "expr": {
                                        "type": "variable",
                                        "value": "existing",
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 600,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 600,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 602,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 602,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 603,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a headers bag for the response externally\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 590,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 590,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 590,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 589,
                    "last-line": 616,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setJsonContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 617,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "jsonOptions",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 617,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 617,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "depth",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "512",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 617,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 617,
                            "char": 85
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 619,
                                    "char": 14
                                },
                                "name": "setContentType",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "application\/json",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 619,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 619,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "UTF-8",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 619,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 619,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 619,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 621,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 621,
                                    "char": 14
                                },
                                "name": "setContent",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "json_encode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "content",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 622,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 622,
                                                    "char": 32
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "jsonOptions",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 622,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 622,
                                                    "char": 45
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "depth",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 622,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 622,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 623,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 623,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 623,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 625,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 625,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 626,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets HTTP response body. The parameter is automatically converted to JSON\n     * and also sets default header: Content-Type: \"application\/json; charset=UTF-8\"\n     *\n     *```php\n     * $response->setJsonContent(\n     *     [\n     *         \"status\" => \"OK\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 618,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 618,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 618,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 617,
                    "last-line": 636,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLastModified",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "datetime",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DateTime",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 637,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 637,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "date",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 639,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 641,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "date",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "datetime",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 641,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 641,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 641,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 647,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "date",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 647,
                                    "char": 14
                                },
                                "name": "setTimezone",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "DateTimeZone",
                                            "dynamic": 0,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "UTC",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 648,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 648,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 649,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 649,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 649,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 654,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 654,
                                    "char": 14
                                },
                                "name": "setHeader",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Last-Modified",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 655,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 655,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "date",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 656,
                                                    "char": 18
                                                },
                                                "name": "format",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "D, d M Y H:i:s",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 656,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 656,
                                                        "char": 40
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 656,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": " GMT",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 657,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 657,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 657,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 657,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 659,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 659,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 660,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets Last-Modified header\n     *\n     *```php\n     * $this->response->setLastModified(\n     *     new DateTime()\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 638,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 638,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 638,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 637,
                    "last-line": 664,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setNotModified",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 667,
                                    "char": 14
                                },
                                "name": "setStatusCode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "304",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 667,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 667,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Not modified",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 667,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 667,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 667,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 669,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 669,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 670,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sends a Not-Modified response\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 666,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 666,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 666,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 665,
                    "last-line": 678,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStatusCode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 679,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 679,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 679,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 681,
                                    "char": 20
                                },
                                {
                                    "variable": "currentHeadersRaw",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 681,
                                    "char": 39
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 681,
                                    "char": 44
                                },
                                {
                                    "variable": "statusCodes",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 681,
                                    "char": 57
                                },
                                {
                                    "variable": "defaultMessage",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 681,
                                    "char": 73
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 683,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 683,
                                            "char": 28
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 683,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 683,
                                    "char": 41
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "currentHeadersRaw",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 684,
                                            "char": 41
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 684,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 684,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 691,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "currentHeadersRaw",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 691,
                                "char": 41
                            },
                            "key": "key",
                            "value": "_",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 692,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 692,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 692,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 692,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strstr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 692,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 692,
                                                    "char": 50
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "HTTP\/",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 692,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 692,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 692,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 692,
                                        "char": 59
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "headers",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 693,
                                                    "char": 25
                                                },
                                                "name": "remove",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 693,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 693,
                                                        "char": 36
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 693,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 694,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 695,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 699,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "message",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 699,
                                    "char": 22
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 699,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 699,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "statusCodes",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "100",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 703,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Continue",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 703,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 703,
                                                        "char": 31
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "101",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 704,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Switching Protocols",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 704,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 704,
                                                        "char": 42
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "102",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 705,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Processing",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 705,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 705,
                                                        "char": 33
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "103",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 706,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Early Hints",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 706,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 706,
                                                        "char": 34
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "200",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 708,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "OK",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 708,
                                                            "char": 25
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 708,
                                                        "char": 25
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "201",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 709,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Created",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 709,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 709,
                                                        "char": 30
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "202",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 710,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Accepted",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 710,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 710,
                                                        "char": 31
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "203",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 711,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Non-Authoritative Information",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 711,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 711,
                                                        "char": 52
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "204",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 712,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "No Content",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 712,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 712,
                                                        "char": 33
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "205",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 713,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Reset Content",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 713,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 713,
                                                        "char": 36
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "206",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 714,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Partial Content",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 714,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 714,
                                                        "char": 38
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "207",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 715,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Multi-status",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 715,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 715,
                                                        "char": 35
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "208",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 716,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Already Reported",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 716,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 716,
                                                        "char": 39
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "226",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 717,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "IM Used",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 717,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 717,
                                                        "char": 30
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "300",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 719,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Multiple Choices",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 719,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 719,
                                                        "char": 39
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "301",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 720,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Moved Permanently",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 720,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 720,
                                                        "char": 40
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "302",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 721,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Found",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 721,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 721,
                                                        "char": 28
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "303",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 722,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "See Other",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 722,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 722,
                                                        "char": 32
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "304",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 723,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Not Modified",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 723,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 723,
                                                        "char": 35
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "305",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 724,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Use Proxy",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 724,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 724,
                                                        "char": 32
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "306",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 725,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Switch Proxy",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 725,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 725,
                                                        "char": 35
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "307",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 726,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Temporary Redirect",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 726,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 726,
                                                        "char": 41
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "308",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 727,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Permanent Redirect",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 727,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 727,
                                                        "char": 41
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "400",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 729,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Bad Request",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 729,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 729,
                                                        "char": 34
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "401",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 730,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Unauthorized",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 730,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 730,
                                                        "char": 35
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "402",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 731,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Payment Required",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 731,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 731,
                                                        "char": 39
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "403",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 732,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Forbidden",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 732,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 732,
                                                        "char": 32
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "404",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 733,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Not Found",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 733,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 733,
                                                        "char": 32
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "405",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 734,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Method Not Allowed",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 734,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 734,
                                                        "char": 41
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "406",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 735,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Not Acceptable",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 735,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 735,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "407",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 736,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Proxy Authentication Required",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 736,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 736,
                                                        "char": 52
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "408",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 737,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Request Time-out",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 737,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 737,
                                                        "char": 39
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "409",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 738,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Conflict",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 738,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 738,
                                                        "char": 31
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "410",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 739,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Gone",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 739,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 739,
                                                        "char": 27
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "411",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 740,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Length Required",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 740,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 740,
                                                        "char": 38
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "412",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 741,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Precondition Failed",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 741,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 741,
                                                        "char": 42
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "413",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 742,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Request Entity Too Large",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 742,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 742,
                                                        "char": 47
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "414",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 743,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Request-URI Too Large",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 743,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 743,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "415",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 744,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Unsupported Media Type",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 744,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 744,
                                                        "char": 45
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "416",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 745,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Requested range not satisfiable",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 745,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 745,
                                                        "char": 54
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "417",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 746,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Expectation Failed",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 746,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 746,
                                                        "char": 41
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "418",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 747,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "I'm a teapot",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 747,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 747,
                                                        "char": 35
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "421",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 748,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Misdirected Request",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 748,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 748,
                                                        "char": 42
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "422",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 749,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Unprocessable Entity",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 749,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 749,
                                                        "char": 43
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "423",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 750,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Locked",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 750,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 750,
                                                        "char": 29
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "424",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 751,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Failed Dependency",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 751,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 751,
                                                        "char": 40
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "425",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 752,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Unordered Collection",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 752,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 752,
                                                        "char": 43
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "426",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 753,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Upgrade Required",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 753,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 753,
                                                        "char": 39
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "428",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 754,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Precondition Required",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 754,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 754,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "429",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 755,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Too Many Requests",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 755,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 755,
                                                        "char": 40
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "431",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 756,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Request Header Fields Too Large",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 756,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 756,
                                                        "char": 54
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "451",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 757,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Unavailable For Legal Reasons",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 757,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 757,
                                                        "char": 52
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "499",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 758,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Client Closed Request",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 758,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 758,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "500",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 760,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Internal Server Error",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 760,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 760,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "501",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 761,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Not Implemented",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 761,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 761,
                                                        "char": 38
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "502",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 762,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Bad Gateway",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 762,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 762,
                                                        "char": 34
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "503",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 763,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Service Unavailable",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 763,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 763,
                                                        "char": 42
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "504",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 764,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Gateway Time-out",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 764,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 764,
                                                        "char": 39
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "505",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 765,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "HTTP Version not supported",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 765,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 765,
                                                        "char": 49
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "506",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 766,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Variant Also Negotiates",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 766,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 766,
                                                        "char": 46
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "507",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 767,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Insufficient Storage",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 767,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 767,
                                                        "char": 43
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "508",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 768,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Loop Detected",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 768,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 768,
                                                        "char": 36
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "510",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 769,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Not Extended",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 769,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 769,
                                                        "char": 35
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "511",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 770,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Network Authentication Required",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 771,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 771,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 771,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 771,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 773,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "statusCodes",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 773,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "code",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 773,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 773,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 773,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 773,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 773,
                                        "char": 50
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
                                                            "value": "Non-standard statuscode given without a message",
                                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                                            "line": 776,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 776,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 776,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 777,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 779,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "defaultMessage",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "statusCodes",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 779,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "code",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 779,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 779,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 779,
                                            "char": 51
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "message",
                                            "expr": {
                                                "type": "variable",
                                                "value": "defaultMessage",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 780,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 780,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 781,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 783,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 783,
                                    "char": 17
                                },
                                "name": "setRaw",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "HTTP\/1.1 ",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 783,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "code",
                                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                                        "line": 783,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 783,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 783,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 783,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 783,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 783,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 783,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 783,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 788,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 788,
                                    "char": 17
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Status",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 789,
                                            "char": 19
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 789,
                                        "char": 19
                                    },
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "code",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 790,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                                    "line": 790,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 790,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                                "line": 791,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 791,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 791,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 791,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 793,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 793,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 794,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the HTTP response code\n     *\n     *```php\n     * $response->setStatusCode(404, \"Not Found\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 680,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 680,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 680,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 679,
                    "last-line": 802,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRawHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "header",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 803,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 805,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 807,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 807,
                                            "char": 28
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 807,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 807,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 809,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 809,
                                    "char": 17
                                },
                                "name": "setRaw",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "header",
                                            "file": "\/app\/phalcon\/Http\/Response.zep",
                                            "line": 809,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response.zep",
                                        "line": 809,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 809,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 811,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 811,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response.zep",
                            "line": 812,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Send a raw header to the response\n     *\n     *```php\n     * $response->setRawHeader(\"HTTP\/1.1 404 Not Found\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Response.zep",
                                    "line": 804,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response.zep",
                                "line": 804,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response.zep",
                        "line": 804,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response.zep",
                    "line": 803,
                    "last-line": 813,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Response.zep",
            "line": 41,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Response.zep",
        "line": 41,
        "char": 5
    }
]