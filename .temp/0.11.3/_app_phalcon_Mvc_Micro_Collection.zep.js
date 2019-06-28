[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Micro",
        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
        "line": 31,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Micro\\Collection\n *\n * Groups Micro-Mvc handlers as controllers\n *\n *```php\n * $app = new \\Phalcon\\Mvc\\Micro();\n *\n * $collection = new Collection();\n *\n * $collection->setHandler(\n *     new PostsController()\n * );\n *\n * $collection->get(\"\/posts\/edit\/{id}\", \"edit\");\n *\n * $app->mount($collection);\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
        "line": 32,
        "char": 5
    },
    {
        "type": "class",
        "name": "Collection",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "CollectionInterface",
                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
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
                    "name": "handler",
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 36,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handlers",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 36,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 38,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "lazy",
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 40,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "prefix",
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 46,
                    "char": 6
                }
            ],
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 47,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 47,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 47,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 47,
                            "char": 81
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 49,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "DELETE",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 49,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 49,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 49,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 49,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 49,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 49,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 49,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 49,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 49,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 51,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 51,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 52,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is DELETE.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 48,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 48,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 48,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 47,
                    "last-line": 58,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 59,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 59,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 59,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 59,
                            "char": 78
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 61,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "GET",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 61,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 61,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 61,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 61,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 61,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 61,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 61,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 61,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 61,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 63,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 63,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 64,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is GET.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 60,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 60,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 60,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 59,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandler",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 71,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handler",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 71,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 71,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 72,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the main handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 70,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 70,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 69,
                    "last-line": 76,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandlers",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 79,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handlers",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 79,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 79,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 80,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the registered handlers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 78,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 78,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 77,
                    "last-line": 84,
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 87,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "prefix",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 87,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 87,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 88,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the collection prefix if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 86,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 86,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 85,
                    "last-line": 94,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 95,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 95,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 95,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 95,
                            "char": 79
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 97,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "HEAD",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 97,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 97,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 97,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 97,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 97,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 97,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 97,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 97,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 97,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 99,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 99,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 100,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is HEAD.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 96,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 96,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 96,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 95,
                    "last-line": 104,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isLazy",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 107,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "lazy",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 107,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 107,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 108,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns if the main handler must be lazy loaded\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 106,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 106,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 105,
                    "last-line": 114,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 115,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 115,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 115,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 115,
                            "char": 78
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 117,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 117,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 117,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 117,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 117,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 117,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 117,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 117,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 117,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 117,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 119,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 119,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 120,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 116,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 116,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 116,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 115,
                    "last-line": 136,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "mapVia",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 137,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 137,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 137,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 137,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 137,
                            "char": 93
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 139,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 139,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 139,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 139,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 139,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 139,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 139,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 139,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 139,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 139,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 141,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 141,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 142,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler via methods.\n     *\n     * ```php\n     * $collection->mapVia(\n     *     \"\/test\",\n     *     \"indexAction\",\n     *     [\"POST\", \"GET\"],\n     *     \"test\"\n     * );\n     * ```\n     *\n     * @param callable handler\n     * @param string|array method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 138,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 138,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 138,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 137,
                    "last-line": 149,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 150,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 150,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 150,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 150,
                            "char": 82
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 152,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "OPTIONS",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 152,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 152,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 152,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 152,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 152,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 152,
                                        "char": 52
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 152,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 152,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 152,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 154,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 154,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 155,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is\n     * OPTIONS.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 151,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 151,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 151,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 150,
                    "last-line": 161,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 162,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 162,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 162,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 162,
                            "char": 80
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 164,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PATCH",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 164,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 164,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 164,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 164,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 164,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 164,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 164,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 164,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 164,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 166,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 166,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 167,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is PATCH.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 163,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 163,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 162,
                    "last-line": 173,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 174,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 174,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 174,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 174,
                            "char": 79
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 176,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "POST",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 176,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 176,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 176,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 176,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 176,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 176,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 176,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 176,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 176,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 178,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 178,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 179,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is POST.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 175,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 175,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 174,
                    "last-line": 185,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 186,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 186,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 186,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 186,
                            "char": 78
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 188,
                                    "char": 14
                                },
                                "name": "addMap",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "PUT",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 188,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 188,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "routePattern",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 188,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 188,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 188,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 188,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                            "line": 188,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 188,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 188,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 190,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 190,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 191,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Maps a route to a handler that only matches if the HTTP method is PUT.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 187,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 187,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 187,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 186,
                    "last-line": 197,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 198,
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
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 198,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 198,
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
                                    "property": "handler",
                                    "expr": {
                                        "type": "variable",
                                        "value": "handler",
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 200,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 200,
                                    "char": 36
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "lazy",
                                    "expr": {
                                        "type": "variable",
                                        "value": "lazy",
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 201,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 201,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 203,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 203,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 204,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the main handler.\n     *\n     * @param callable|string handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 199,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 199,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 199,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 198,
                    "last-line": 208,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 209,
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
                                    "property": "lazy",
                                    "expr": {
                                        "type": "variable",
                                        "value": "lazy",
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 211,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 211,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 213,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 213,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 214,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 210,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 210,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 210,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 209,
                    "last-line": 218,
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
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 219,
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
                                    "property": "prefix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 221,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 221,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 223,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 223,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 224,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 220,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                "line": 220,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                        "line": 220,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 219,
                    "last-line": 231,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "addMap",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 232,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "routePattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 232,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 232,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 232,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "handlers",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                    "line": 234,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                "line": 234,
                                                "char": 39
                                            },
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "routePattern",
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                    "line": 234,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                "line": 234,
                                                "char": 53
                                            },
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                    "line": 234,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                "line": 234,
                                                "char": 62
                                            },
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                    "line": 234,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                                "line": 234,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                        "line": 234,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                                    "line": 234,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                            "line": 235,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Internal function to add a handler to the group.\n     *\n     * @param string|array    method\n     * @param callable|string handler\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
                    "line": 232,
                    "last-line": 236,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
            "line": 32,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Micro\/Collection.zep",
        "line": 32,
        "char": 5
    }
]