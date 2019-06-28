[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator\\Adapter",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Query\\Builder",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                "line": 14,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\RepositoryInterface",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                "line": 15,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Exception",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                "line": 16,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                "line": 17,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 40,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Paginator\\Adapter\\QueryBuilder\n *\n * Pagination using a PHQL query builder as source of data\n *\n * ```php\n * use Phalcon\\Paginator\\Adapter\\QueryBuilder;\n *\n * $builder = $this->modelsManager->createBuilder()\n *                 ->columns(\"id, name\")\n *                 ->from(Robots::class)\n *                 ->orderBy(\"name\");\n *\n * $paginator = new QueryBuilder(\n *     [\n *         \"builder\" => $builder,\n *         \"limit\"   => 20,\n *         \"page\"    => 1,\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 41,
        "char": 5
    },
    {
        "type": "class",
        "name": "QueryBuilder",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "builder",
                    "docblock": "**\n     * Paginator's data\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "columns",
                    "docblock": "**\n     * Columns for count query if builder has having\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                    "line": 55,
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
                            "name": "config",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 56,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "builder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 58,
                                    "char": 20
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 58,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 60,
                            "char": 10
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
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 60,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "limit",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 60,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 60,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 60,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 60,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 60,
                                "char": 42
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
                                                    "value": "Parameter 'limit' is required",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 61,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 61,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 61,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 62,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
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
                                            "value": "builder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 64,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 64,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "builder",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 64,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 64,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 64,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 64,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 64,
                                "char": 53
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
                                                    "value": "Parameter 'builder' is required",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 65,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 65,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 65,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 66,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 68,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "columns",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 68,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 68,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "columns",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 68,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 68,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 68,
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
                                            "property": "columns",
                                            "expr": {
                                                "type": "variable",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 69,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 69,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 70,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 72,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 72,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 72,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 72,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 74,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 74,
                                    "char": 14
                                },
                                "name": "setQueryBuilder",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "builder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 74,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 74,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 74,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 75,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Paginator\\Adapter\\QueryBuilder\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                    "line": 56,
                    "last-line": 78,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCurrentPage",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 81,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "page",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 81,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 81,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 82,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the current page number\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 80,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                        "line": 80,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                    "line": 79,
                    "last-line": 86,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getQueryBuilder",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 89,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "builder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 89,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 89,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 90,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get query builder object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Builder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 88,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 88,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                        "line": 88,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                    "line": 87,
                    "last-line": 94,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "paginate",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "originalBuilder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 97,
                                    "char": 28
                                },
                                {
                                    "variable": "builder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 97,
                                    "char": 37
                                },
                                {
                                    "variable": "totalBuilder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 97,
                                    "char": 51
                                },
                                {
                                    "variable": "totalPages",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 97,
                                    "char": 63
                                },
                                {
                                    "variable": "limit",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 97,
                                    "char": 70
                                },
                                {
                                    "variable": "number",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 19
                                },
                                {
                                    "variable": "query",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 26
                                },
                                {
                                    "variable": "previous",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 36
                                },
                                {
                                    "variable": "items",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 43
                                },
                                {
                                    "variable": "totalQuery",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 55
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 63
                                },
                                {
                                    "variable": "row",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 68
                                },
                                {
                                    "variable": "rowcount",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 98,
                                    "char": 78
                                },
                                {
                                    "variable": "next",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 17
                                },
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 22
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 31
                                },
                                {
                                    "variable": "db",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 35
                                },
                                {
                                    "variable": "model",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 42
                                },
                                {
                                    "variable": "modelClass",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 54
                                },
                                {
                                    "variable": "dbService",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 65
                                },
                                {
                                    "variable": "groups",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 99,
                                    "char": 73
                                },
                                {
                                    "variable": "groupColumn",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 100,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 101,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "hasHaving",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 101,
                                    "char": 23
                                },
                                {
                                    "variable": "hasGroup",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 101,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 102,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "numberPage",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 102,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 104,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "originalBuilder",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 104,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "builder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 104,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 104,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 104,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 105,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columns",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 105,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "columns",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 105,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 105,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 105,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 110,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "builder",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "originalBuilder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 110,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 110,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 110,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 115,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "totalBuilder",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "builder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 115,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 115,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 115,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 117,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "limit",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 117,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "limitRows",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 117,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 117,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 117,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 118,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "numberPage",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 118,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "page",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 118,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 118,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 118,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 118,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 120,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "numberPage",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 120,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 120,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "numberPage",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 121,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 121,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 122,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 124,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "number",
                                    "expr": {
                                        "type": "mul",
                                        "left": {
                                            "type": "variable",
                                            "value": "limit",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 124,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "list",
                                            "left": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "numberPage",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 124,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 124,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 124,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 124,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 124,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 124,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 129,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "number",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 129,
                                    "char": 19
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "limit",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 129,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 129,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "builder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 130,
                                            "char": 21
                                        },
                                        "name": "limit",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "limit",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 130,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 130,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 130,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 131,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "builder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 132,
                                            "char": 21
                                        },
                                        "name": "limit",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "limit",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 132,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 132,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "number",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 132,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 132,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 132,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 133,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 135,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "query",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "builder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 135,
                                            "char": 29
                                        },
                                        "name": "getQuery",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 135,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 135,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 137,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "numberPage",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 137,
                                    "char": 24
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 137,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 137,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "previous",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 138,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 138,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 139,
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
                                            "variable": "previous",
                                            "expr": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "numberPage",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 140,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 140,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 140,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 140,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 141,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 146,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "items",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "query",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 146,
                                            "char": 27
                                        },
                                        "name": "execute",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 146,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 146,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 148,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hasHaving",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "totalBuilder",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 148,
                                                    "char": 45
                                                },
                                                "name": "getHaving",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 148,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 148,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 148,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 148,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 150,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "groups",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "totalBuilder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 150,
                                            "char": 35
                                        },
                                        "name": "getGroupBy",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 150,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 150,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 152,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hasGroup",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "groups",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 152,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 152,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 152,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 152,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 158,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "variable",
                                    "value": "hasHaving",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 158,
                                    "char": 23
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "variable",
                                        "value": "hasGroup",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 158,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 158,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 158,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 159,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 159,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 159,
                                        "char": 39
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
                                                            "value": "When having is set there should be columns option provided for which calculate row count",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 162,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 162,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 162,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 163,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 165,
                                    "char": 24
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "totalBuilder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 165,
                                            "char": 26
                                        },
                                        "name": "columns",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "columns",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 165,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 165,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 165,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 166,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "totalBuilder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 167,
                                            "char": 26
                                        },
                                        "name": "columns",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "COUNT(*) [rowcount]",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 167,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 167,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 167,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 168,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 173,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "hasGroup",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 173,
                                "char": 21
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
                                                "value": "groups",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 174,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 174,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 174,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 174,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "groupColumn",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "implode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": ", ",
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 175,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 175,
                                                                "char": 45
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "groups",
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 175,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 175,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 175,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 175,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 176,
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
                                                    "variable": "groupColumn",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "groups",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 177,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 177,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 178,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 180,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "hasHaving",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 180,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 180,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "totalBuilder",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 181,
                                                        "char": 30
                                                    },
                                                    "name": "groupBy",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "null",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 181,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 181,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 181,
                                                    "char": 45
                                                },
                                                "name": "columns",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "COUNT(DISTINCT ",
                                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                                "line": 183,
                                                                                "char": 41
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "groupColumn",
                                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                                "line": 183,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 183,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ") AS [rowcount]",
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 184,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                        "line": 184,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 184,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 185,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 185,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 185,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 186,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "totalBuilder",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 187,
                                                    "char": 30
                                                },
                                                "name": "columns",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "DISTINCT ",
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 189,
                                                                            "char": 35
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "groupColumn",
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 190,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                        "line": 190,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 190,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 191,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 191,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 191,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 192,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 193,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 198,
                            "char": 20
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "totalBuilder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 198,
                                    "char": 22
                                },
                                "name": "orderBy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 198,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 198,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 198,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 203,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "totalQuery",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "totalBuilder",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 203,
                                            "char": 39
                                        },
                                        "name": "getQuery",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 203,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 203,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 209,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "hasHaving",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 209,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "totalQuery",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 210,
                                                    "char": 34
                                                },
                                                "name": "getSql",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 210,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 210,
                                            "char": 43
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "modelClass",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "builder",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 211,
                                                    "char": 38
                                                },
                                                "name": "getModels",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 211,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 211,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 213,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "modelClass",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 213,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 213,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 213,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 213,
                                        "char": 45
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
                                                            "value": "Model not defined in builder",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 214,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 214,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 214,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 215,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 217,
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
                                                "value": "modelClass",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 217,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 217,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 217,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 217,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "modelClass",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "array_values",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "modelClass",
                                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                        "line": 218,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 218,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 218,
                                                            "char": 58
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 218,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 218,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 218,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 219,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 221,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "model",
                                            "expr": {
                                                "type": "new",
                                                "class": "modelClass",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 221,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 221,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 222,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "dbService",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 222,
                                                    "char": 35
                                                },
                                                "name": "getReadConnectionService",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 222,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 222,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 223,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "db",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "totalBuilder",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 223,
                                                        "char": 35
                                                    },
                                                    "name": "getDI",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 223,
                                                    "char": 44
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "dbService",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 223,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 223,
                                                        "char": 58
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 223,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 223,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 225,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "row",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "db",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 225,
                                                    "char": 26
                                                },
                                                "name": "fetchOne",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "SELECT COUNT(*) as \\\"rowcount\\\" FROM (",
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 226,
                                                                    "char": 56
                                                                },
                                                                "right": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "sql",
                                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                        "line": 226,
                                                                        "char": 62
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "sql",
                                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                        "line": 226,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 226,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 226,
                                                                "char": 68
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": ") as T1",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 226,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 226,
                                                            "char": 77
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 226,
                                                        "char": 77
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Db",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 227,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "FETCH_ASSOC",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 227,
                                                                "char": 32
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 227,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 227,
                                                        "char": 32
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "sql",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 228,
                                                                "char": 20
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "bind",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 228,
                                                                "char": 25
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 229,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 229,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 229,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 229,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 231,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "rowcount",
                                            "expr": {
                                                "type": "ternary",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "row",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 231,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "intval",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "row",
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 231,
                                                                    "char": 44
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "rowcount",
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 231,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 231,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 231,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 231,
                                                    "char": 56
                                                },
                                                "extra": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 231,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 231,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 231,
                                            "char": 59
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "totalPages",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "intval",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "ceil",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "div",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "rowcount",
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 232,
                                                                            "char": 51
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "limit",
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 232,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                        "line": 232,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 232,
                                                                    "char": 58
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 232,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 232,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 232,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 232,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 233,
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
                                            "variable": "result",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "totalQuery",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 234,
                                                    "char": 37
                                                },
                                                "name": "execute",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 234,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 234,
                                            "char": 47
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "row",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "result",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 235,
                                                    "char": 30
                                                },
                                                "name": "getFirst",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 235,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 235,
                                            "char": 41
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "rowcount",
                                            "expr": {
                                                "type": "ternary",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "row",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 236,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "intval",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "row",
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 236,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "rowcount",
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 236,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                "line": 236,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 236,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 236,
                                                    "char": 56
                                                },
                                                "extra": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 236,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 236,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 236,
                                            "char": 59
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "totalPages",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "intval",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "ceil",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "div",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "rowcount",
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 237,
                                                                            "char": 51
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "limit",
                                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                            "line": 237,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                        "line": 237,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                                    "line": 237,
                                                                    "char": 58
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 237,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 237,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 237,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 237,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 238,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 240,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "numberPage",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 240,
                                    "char": 23
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "totalPages",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 240,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 240,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "next",
                                            "expr": {
                                                "type": "add",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "numberPage",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 241,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 241,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 241,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 241,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 242,
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
                                            "variable": "next",
                                            "expr": {
                                                "type": "variable",
                                                "value": "totalPages",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                "line": 243,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 243,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 244,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 246,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 246,
                                    "char": 21
                                },
                                "name": "getRepository",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 248,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_ITEMS",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 248,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 248,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "items",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 248,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 248,
                                                    "char": 68
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 249,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_TOTAL_ITEMS",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 249,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 249,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "rowcount",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 249,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 249,
                                                    "char": 71
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 250,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_LIMIT",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 250,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 250,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 250,
                                                            "char": 68
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "limitRows",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 250,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 250,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 250,
                                                    "char": 78
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 251,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_FIRST_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 251,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 251,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 251,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 251,
                                                    "char": 64
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 252,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_PREVIOUS_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 252,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 252,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "previous",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 252,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 252,
                                                    "char": 71
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 253,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_CURRENT_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 253,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 253,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "numberPage",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 253,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 253,
                                                    "char": 73
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 254,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_NEXT_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 254,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 254,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "next",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 254,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 254,
                                                    "char": 67
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 255,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_LAST_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                            "line": 255,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 255,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "totalPages",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                        "line": 256,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                                    "line": 256,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                            "line": 257,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 257,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 257,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 258,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a slice of the resultset to show in the pagination\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RepositoryInterface",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 96,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 96,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                        "line": 96,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                    "line": 95,
                    "last-line": 262,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setQueryBuilder",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "builder",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Builder",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 263,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 263,
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
                                    "property": "builder",
                                    "expr": {
                                        "type": "variable",
                                        "value": "builder",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                        "line": 265,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 265,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 267,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 267,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                            "line": 268,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set query builder object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryBuilder",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                    "line": 264,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                                "line": 264,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                        "line": 264,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
                    "line": 263,
                    "last-line": 269,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
            "line": 41,
            "char": 5
        },
        "file": "\/app\/phalcon\/Paginator\/Adapter\/QueryBuilder.zep",
        "line": 41,
        "char": 5
    }
]