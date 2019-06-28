[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Di",
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Di\/Service.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Di\/Service.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Exception",
                "file": "\/app\/phalcon\/Di\/Service.zep",
                "line": 15,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Exception\\ServiceResolutionException",
                "file": "\/app\/phalcon\/Di\/Service.zep",
                "line": 16,
                "char": 52
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\ServiceInterface",
                "file": "\/app\/phalcon\/Di\/Service.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Service\\Builder",
                "file": "\/app\/phalcon\/Di\/Service.zep",
                "line": 18,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 31,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents individually a service in the services container\n *\n *```php\n * $service = new \\Phalcon\\Di\\Service(\n *     \"request\",\n *     \\Phalcon\\Http\\Request::class\n * );\n *\n * $request = service->resolve();\n *```\n *",
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 32,
        "char": 5
    },
    {
        "type": "class",
        "name": "Service",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ServiceInterface",
                "file": "\/app\/phalcon\/Di\/Service.zep",
                "line": 33,
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
                    "name": "definition",
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 38,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "resolved",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 39,
                        "char": 31
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 43,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "shared",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 44,
                        "char": 29
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 46,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sharedInstance",
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 50,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 51,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "shared",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 51,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 51,
                            "char": 74
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
                                    "property": "definition",
                                    "expr": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 53,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 53,
                                    "char": 42
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "shared",
                                    "expr": {
                                        "type": "variable",
                                        "value": "shared",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 54,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 54,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Di\\Service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 52,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 51,
                    "last-line": 59,
                    "char": 25
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "__set_state",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 60,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 62,
                                    "char": 23
                                },
                                {
                                    "variable": "shared",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 62,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 64,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 64,
                                            "char": 64
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 64,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "_definition",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 64,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 64,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 64,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 64,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 64,
                                "char": 64
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
                                                    "value": "The attribute '_definition' is required",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 65,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 65,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 65,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 66,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 68,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "shared",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 68,
                                            "char": 56
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 68,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "_shared",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 68,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 68,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 68,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 68,
                                    "char": 56
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 68,
                                "char": 56
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
                                                    "value": "The attribute '_shared' is required",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 69,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 69,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 69,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 70,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 72,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "self",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 72,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 72,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "shared",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 72,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 72,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 72,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Restore the internal state of a service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 61,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 61,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 61,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 60,
                    "last-line": 77,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefinition",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 80,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "definition",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 80,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 80,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 81,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the service definition\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 78,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParameter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 88,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 90,
                                    "char": 23
                                },
                                {
                                    "variable": "arguments",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 90,
                                    "char": 34
                                },
                                {
                                    "variable": "parameter",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 90,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 92,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "definition",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 92,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 92,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 92,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 92,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 94,
                            "char": 10
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
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 94,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 94,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 94,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 94,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 94,
                                "char": 48
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
                                                    "value": "Definition must be an array to obtain its parameters",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 97,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 97,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 97,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 98,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 103,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "arguments",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 103,
                                    "char": 51
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 103,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "arguments",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 103,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 103,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 103,
                                "char": 51
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "parameter",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 104,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "arguments",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 104,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "position",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 104,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 104,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 104,
                                        "char": 53
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameter",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 105,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 106,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 107,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 109,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 109,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 110,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a parameter in a specific position\n     *\n     * @return array\n     *",
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 88,
                    "last-line": 114,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isResolved",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 117,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "resolved",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 117,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 117,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns true if the service was resolved\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 116,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 116,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 115,
                    "last-line": 122,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isShared",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 125,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "shared",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 125,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 125,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 126,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the service is shared or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 124,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 124,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 123,
                    "last-line": 132,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "resolve",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 133,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 133,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 133,
                                "char": 70
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 133,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 133,
                            "char": 78
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "found",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 135,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 136,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "shared",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 136,
                                    "char": 19
                                },
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 136,
                                    "char": 31
                                },
                                {
                                    "variable": "sharedInstance",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 136,
                                    "char": 47
                                },
                                {
                                    "variable": "instance",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 136,
                                    "char": 57
                                },
                                {
                                    "variable": "builder",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 136,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 138,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "shared",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 138,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "shared",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 138,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 138,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 138,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 143,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "shared",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 143,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "sharedInstance",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 144,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "sharedInstance",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 144,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 144,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 144,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 145,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "sharedInstance",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 145,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 145,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 145,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "sharedInstance",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 146,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 147,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 148,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 150,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "found",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 150,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 150,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "instance",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 151,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 151,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 153,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "definition",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 153,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 153,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 153,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 153,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 154,
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
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 154,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 154,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 154,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 154,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "class_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "definition",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 159,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 159,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 159,
                                        "char": 41
                                    },
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
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 160,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                        "line": 160,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                        "line": 160,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 160,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "count",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "parameters",
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 160,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 160,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 160,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 160,
                                                "char": 68
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "instance",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "create_instance_params",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "definition",
                                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                            "line": 162,
                                                                            "char": 35
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 162,
                                                                        "char": 35
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "parameters",
                                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                            "line": 164,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 164,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 164,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 164,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 165,
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
                                                            "variable": "instance",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "create_instance",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "definition",
                                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                            "line": 166,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 166,
                                                                        "char": 62
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 166,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 166,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 167,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 168,
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
                                                    "variable": "found",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                        "line": 169,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 169,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 170,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 171,
                                    "char": 9
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
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 177,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 177,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 177,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 177,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "instanceof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "definition",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 178,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "Closure",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 178,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 178,
                                                "char": 50
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
                                                                "value": "container",
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 183,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 183,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 183,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                        "line": 183,
                                                        "char": 51
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "definition",
                                                                    "expr": {
                                                                        "type": "scall",
                                                                        "dynamic-class": 0,
                                                                        "class": "Closure",
                                                                        "dynamic": 0,
                                                                        "name": "bind",
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "definition",
                                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                    "line": 184,
                                                                                    "char": 66
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                "line": 184,
                                                                                "char": 66
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "container",
                                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                    "line": 184,
                                                                                    "char": 77
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                "line": 184,
                                                                                "char": 77
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 184,
                                                                        "char": 78
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                    "line": 184,
                                                                    "char": 78
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 185,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 187,
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
                                                                "value": "parameters",
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 187,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 187,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 187,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                        "line": 187,
                                                        "char": 51
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "instance",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "call_user_func_array",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "definition",
                                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                    "line": 189,
                                                                                    "char": 39
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                "line": 189,
                                                                                "char": 39
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "parameters",
                                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                    "line": 191,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                "line": 191,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 191,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                    "line": 191,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 192,
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
                                                                    "variable": "instance",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "call_user_func",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "definition",
                                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                    "line": 193,
                                                                                    "char": 65
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                                "line": 193,
                                                                                "char": 65
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 193,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                    "line": 193,
                                                                    "char": 66
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 194,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 195,
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
                                                            "variable": "instance",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "definition",
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 196,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 196,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 197,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 198,
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
                                                        "value": "definition",
                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                        "line": 202,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 202,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 202,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 202,
                                                "char": 47
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "builder",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Builder",
                                                                "dynamic": 0,
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 203,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 203,
                                                            "char": 48
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "instance",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "builder",
                                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                    "line": 204,
                                                                    "char": 44
                                                                },
                                                                "name": "build",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "container",
                                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                            "line": 205,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 205,
                                                                        "char": 38
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "definition",
                                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                            "line": 206,
                                                                            "char": 39
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 206,
                                                                        "char": 39
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "parameters",
                                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                            "line": 208,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                        "line": 208,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 208,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 208,
                                                            "char": 26
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 209,
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
                                                            "variable": "found",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                                "line": 210,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 210,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 211,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 212,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 213,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 218,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "found",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 218,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 218,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 218,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 218,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "ServiceResolutionException",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 219,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 220,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 225,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "shared",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 225,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "sharedInstance",
                                            "expr": {
                                                "type": "variable",
                                                "value": "instance",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 226,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 226,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 227,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 229,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "resolved",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 229,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 229,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 231,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "instance",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 231,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 232,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolves the service\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 133,
                    "last-line": 236,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefinition",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 237,
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
                                    "property": "definition",
                                    "expr": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 239,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 239,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 240,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the service definition\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 238,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 237,
                    "last-line": 244,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setParameter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 245,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "parameter",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 245,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 247,
                                    "char": 23
                                },
                                {
                                    "variable": "arguments",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 247,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 249,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "definition",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 249,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 249,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 249,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 249,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 251,
                            "char": 10
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
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 251,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 251,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 251,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 251,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 251,
                                "char": 48
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
                                                    "value": "Definition must be an array to update its parameters",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 254,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 254,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 254,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 255,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 260,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "arguments",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 260,
                                    "char": 51
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 260,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "arguments",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 260,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 260,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 260,
                                "char": 51
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "arguments",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "position",
                                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                                    "line": 261,
                                                    "char": 35
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameter",
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 261,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 261,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 262,
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
                                            "variable": "arguments",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "variable",
                                                            "value": "position",
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 263,
                                                            "char": 38
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameter",
                                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                                            "line": 263,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                                        "line": 263,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                                "line": 263,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 263,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 264,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 269,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "definition",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "arguments",
                                            "file": "\/app\/phalcon\/Di\/Service.zep",
                                            "line": 269,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "arguments",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 269,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 269,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 274,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "definition",
                                    "expr": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 274,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 274,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 276,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 276,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 277,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Changes a parameter in the definition without resolve the service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 246,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di\/Service.zep",
                                "line": 246,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 246,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 245,
                    "last-line": 281,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setShared",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "shared",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 282,
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
                                    "property": "shared",
                                    "expr": {
                                        "type": "variable",
                                        "value": "shared",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 284,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 284,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 285,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the service is shared or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 283,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 282,
                    "last-line": 289,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setSharedInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sharedInstance",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 290,
                            "char": 57
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
                                    "property": "sharedInstance",
                                    "expr": {
                                        "type": "variable",
                                        "value": "sharedInstance",
                                        "file": "\/app\/phalcon\/Di\/Service.zep",
                                        "line": 292,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service.zep",
                                    "line": 292,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service.zep",
                            "line": 293,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets\/Resets the shared instance related to the service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/Service.zep",
                        "line": 291,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service.zep",
                    "line": 290,
                    "last-line": 294,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Di\/Service.zep",
            "line": 32,
            "char": 5
        },
        "file": "\/app\/phalcon\/Di\/Service.zep",
        "line": 32,
        "char": 5
    }
]