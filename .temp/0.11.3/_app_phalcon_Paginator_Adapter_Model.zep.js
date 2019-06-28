[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator\\Adapter",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Exception",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                "line": 13,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                "line": 14,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\RepositoryInterface",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                "line": 15,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
        "line": 36,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Paginator\\Adapter\\Model\n *\n * This adapter allows to paginate data using a Phalcon\\Mvc\\Model resultset as a\n * base.\n *\n * ```php\n * use Phalcon\\Paginator\\Adapter\\Model;\n *\n * $paginator = new Model(\n *     [\n *         \"data\"  => Robots::find(),\n *         \"limit\" => 25,\n *         \"page\"  => $currentPage,\n *     ]\n * );\n *\n * $paginate = $paginator->paginate();\n *```\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
        "line": 37,
        "char": 5
    },
    {
        "type": "class",
        "name": "Model",
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
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 44,
                                    "char": 19
                                },
                                {
                                    "variable": "items",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 44,
                                    "char": 26
                                },
                                {
                                    "variable": "pageItems",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 44,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 45,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "pageNumber",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 23
                                },
                                {
                                    "variable": "show",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 29
                                },
                                {
                                    "variable": "n",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 32
                                },
                                {
                                    "variable": "start",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 39
                                },
                                {
                                    "variable": "lastShowPage",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 53
                                },
                                {
                                    "variable": "i",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 56
                                },
                                {
                                    "variable": "next",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 62
                                },
                                {
                                    "variable": "totalPages",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 45,
                                    "char": 74
                                },
                                {
                                    "variable": "previous",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 46,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 48,
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
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 48,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "limitRows",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 48,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 48,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 48,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 48,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "config",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 49,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 49,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 49,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 49,
                                    "char": 38
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
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 50,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 50,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 50,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 50,
                                    "char": 38
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
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 51,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "page",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 51,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 51,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 51,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 51,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 53,
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
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 53,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 53,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 53,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 53,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 53,
                                "char": 44
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
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 54,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 54,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 54,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 55,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 58,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less-equal",
                                "left": {
                                    "type": "variable",
                                    "value": "pageNumber",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 58,
                                    "char": 23
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 58,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 58,
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
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 59,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 59,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 60,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 63,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "less-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "show",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 63,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 63,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 63,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 63,
                                "char": 30
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
                                                    "value": "The start page number is zero or less",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 64,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 64,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 64,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 65,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 67,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "n",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "items",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 67,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 67,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 67,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 67,
                                    "char": 40
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "lastShowPage",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "variable",
                                            "value": "pageNumber",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 68,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 68,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 68,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 68,
                                    "char": 42
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "start",
                                    "expr": {
                                        "type": "mul",
                                        "left": {
                                            "type": "variable",
                                            "value": "show",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 69,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "lastShowPage",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 69,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 69,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 69,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pageItems",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 70,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 70,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 72,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "mod",
                                    "left": {
                                        "type": "variable",
                                        "value": "n",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 72,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "show",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 72,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 72,
                                    "char": 22
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 72,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 72,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "totalPages",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "add",
                                                        "left": {
                                                            "type": "div",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "n",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                                "line": 73,
                                                                "char": 39
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "show",
                                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                                "line": 73,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 73,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 73,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 73,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 73,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 73,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 73,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 74,
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
                                            "variable": "totalPages",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "div",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "n",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 75,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "show",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 75,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 75,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 75,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 75,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 75,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 78,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "n",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 78,
                                    "char": 14
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 78,
                                    "char": 18
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 78,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "start",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 80,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "n",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 80,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 80,
                                        "char": 26
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "items",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 81,
                                                    "char": 23
                                                },
                                                "name": "seek",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "start",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 81,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 81,
                                                        "char": 34
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 81,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 82,
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
                                                    "value": "items",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 83,
                                                    "char": 23
                                                },
                                                "name": "seek",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 83,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 83,
                                                        "char": 30
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 83,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 85,
                                            "char": 19
                                        },
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
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 85,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 85,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 86,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 89,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "i",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 89,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 89,
                                            "char": 22
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 91,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "items",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 91,
                                            "char": 25
                                        },
                                        "name": "valid",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 91,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "pageItems",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "items",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 92,
                                                            "char": 41
                                                        },
                                                        "name": "current",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 92,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 92,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 94,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "greater-equal",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "i",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 94,
                                                    "char": 22
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "show",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 94,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 94,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 96,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 98,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "incr",
                                                    "variable": "i",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 98,
                                                    "char": 24
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 100,
                                            "char": 21
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "items",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 100,
                                                    "char": 23
                                                },
                                                "name": "next",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 100,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 101,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 102,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 105,
                            "char": 11
                        },
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
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 105,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 105,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 105,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 105,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 107,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "next",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 107,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "totalPages",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 107,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 107,
                                "char": 30
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
                                                "type": "variable",
                                                "value": "totalPages",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 108,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 108,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 109,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 111,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "pageNumber",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 111,
                                    "char": 23
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 111,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 111,
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
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 112,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 112,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 112,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 112,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 113,
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
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                "line": 114,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 114,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 115,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 117,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 117,
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
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 119,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_ITEMS",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 119,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 119,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "pageItems",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 119,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 119,
                                                    "char": 72
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 120,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_TOTAL_ITEMS",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 120,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 120,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "n",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 120,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 120,
                                                    "char": 64
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 121,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_LIMIT",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 121,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 121,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 121,
                                                            "char": 68
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "limitRows",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 121,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 121,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 121,
                                                    "char": 78
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 122,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_FIRST_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 122,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 122,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 122,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 122,
                                                    "char": 64
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 123,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_PREVIOUS_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 123,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 123,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "previous",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 123,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 123,
                                                    "char": 71
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 124,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_CURRENT_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 124,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 124,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "pageNumber",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 124,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 124,
                                                    "char": 73
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 125,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_NEXT_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 125,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 125,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "next",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 125,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 125,
                                                    "char": 67
                                                },
                                                {
                                                    "key": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RepositoryInterface",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 126,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "PROPERTY_LAST_PAGE",
                                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                            "line": 126,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 126,
                                                        "char": 61
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "totalPages",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                        "line": 127,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                                    "line": 127,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                            "line": 128,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                        "line": 128,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 128,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                            "line": 129,
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
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                    "line": 43,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                                "line": 43,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                        "line": 43,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
                    "line": 42,
                    "last-line": 130,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
            "line": 37,
            "char": 5
        },
        "file": "\/app\/phalcon\/Paginator\/Adapter\/Model.zep",
        "line": 37,
        "char": 5
    }
]