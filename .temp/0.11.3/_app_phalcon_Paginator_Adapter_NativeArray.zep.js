[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator\\Adapter",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Exception",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                "line": 13,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                "line": 14,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\RepositoryInterface",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                "line": 15,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
        "line": 39,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Paginator\\Adapter\\NativeArray\n *\n * Pagination using a PHP array as source of data\n *\n * ```php\n * use Phalcon\\Paginator\\Adapter\\NativeArray;\n *\n * $paginator = new NativeArray(\n *     [\n *         \"data\"  => [\n *             [\"id\" => 1, \"name\" => \"Artichoke\"],\n *             [\"id\" => 2, \"name\" => \"Carrots\"],\n *             [\"id\" => 3, \"name\" => \"Beet\"],\n *             [\"id\" => 4, \"name\" => \"Lettuce\"],\n *             [\"id\" => 5, \"name\" => \"\"],\n *         ],\n *         \"limit\" => 2,\n *         \"page\"  => $currentPage,\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
        "line": 40,
        "char": 5
    },
    {
        "type": "class",
        "name": "NativeArray",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "definition": {
            "methods": [
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
                                    "variable": "config",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 47,
                                    "char": 19
                                },
                                {
                                    "variable": "items",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 47,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 48,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "show",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 17
                                },
                                {
                                    "variable": "pageNumber",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 29
                                },
                                {
                                    "variable": "totalPages",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 41
                                },
                                {
                                    "variable": "number",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 49
                                },
                                {
                                    "variable": "previous",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 59
                                },
                                {
                                    "variable": "next",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 49,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "double",
                            "variables": [
                                {
                                    "variable": "roundedTotal",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 49,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 54,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "config",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 54,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 54,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 54,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 54,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "items",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 55,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 55,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 55,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 55,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 57,
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
                                            "value": "items",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 57,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 57,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 57,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 57,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                "line": 57,
                                "char": 43
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
                                                    "value": "Invalid data for paginator",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 58,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 58,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 58,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 59,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 61,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "show",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 61,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "limitRows",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 61,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 61,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 61,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 61,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pageNumber",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 62,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "page",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 62,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 62,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 62,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 62,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 64,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less-equal",
                                "left": {
                                    "type": "variable",
                                    "value": "pageNumber",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 64,
                                    "char": 23
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 64,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                "line": 64,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "pageNumber",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 65,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 65,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 66,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 68,
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
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "items",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 68,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 68,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 68,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 68,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "roundedTotal",
                                    "expr": {
                                        "type": "div",
                                        "left": {
                                            "type": "variable",
                                            "value": "number",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 69,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "floatval",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "show",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 69,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 69,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 69,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 69,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 69,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "totalPages",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "variable",
                                            "value": "roundedTotal",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 70,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 70,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 70,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 75,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "totalPages",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 75,
                                    "char": 24
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "roundedTotal",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 75,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                "line": 75,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "incr",
                                            "variable": "totalPages",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 76,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 77,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 79,
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
                                        "type": "fcall",
                                        "name": "array_slice",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "items",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 80,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 80,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "mul",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "show",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 81,
                                                        "char": 18
                                                    },
                                                    "right": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "sub",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "pageNumber",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                                "line": 81,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                                "line": 81,
                                                                "char": 35
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 81,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 81,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 81,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 81,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "show",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 83,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 83,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 83,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 83,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 86,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "pageNumber",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 86,
                                    "char": 23
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "totalPages",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 86,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                "line": 86,
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
                                                    "value": "pageNumber",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 87,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 87,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 87,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 87,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 88,
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
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 89,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 89,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 92,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "pageNumber",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 92,
                                    "char": 23
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 92,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                "line": 92,
                                "char": 27
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
                                                "type": "sub",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "pageNumber",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 93,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 93,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 93,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 93,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 94,
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
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                "line": 95,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 95,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 96,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 98,
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
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 100,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_ITEMS",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 100,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 100,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "items",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 100,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 100,
                                                    "char": 68
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 101,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_TOTAL_ITEMS",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 101,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 101,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "number",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 101,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 101,
                                                    "char": 69
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 102,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_LIMIT",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 102,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 102,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 102,
                                                            "char": 68
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "limitRows",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 102,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 102,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 102,
                                                    "char": 78
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 103,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_FIRST_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 103,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 103,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 103,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 103,
                                                    "char": 64
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 104,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_PREVIOUS_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 104,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 104,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "previous",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 104,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 104,
                                                    "char": 71
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 105,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_CURRENT_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 105,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 105,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "pageNumber",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 105,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 105,
                                                    "char": 73
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 106,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_NEXT_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 106,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 106,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "next",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 106,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 106,
                                                    "char": 67
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 107,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_LAST_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                            "line": 107,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 107,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "totalPages",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                        "line": 108,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                                    "line": 108,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                            "line": 109,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                        "line": 109,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                "line": 109,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                            "line": 110,
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
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                    "line": 46,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                                "line": 46,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                        "line": 46,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
                    "line": 45,
                    "last-line": 111,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
            "line": 40,
            "char": 5
        },
        "file": "\/app\/phalcon\/Paginator\/Adapter\/NativeArray.zep",
        "line": 40,
        "char": 5
    }
]