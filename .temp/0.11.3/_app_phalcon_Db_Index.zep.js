[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Index.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/Index.zep",
        "line": 41,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Allows to define indexes to be used on tables. Indexes are a common way\n * to enhance database performance. An index allows the database server to find\n * and retrieve specific rows much faster than it could do without an index\n *\n *```php\n * \/\/ Define new unique index\n * $index_unique = new \\Phalcon\\Db\\Index(\n *     'column_UNIQUE',\n *     [\n *         'column',\n *         'column',\n *     ],\n *     'UNIQUE'\n * );\n *\n * \/\/ Define new primary index\n * $index_primary = new \\Phalcon\\Db\\Index(\n *     'PRIMARY',\n *     [\n *         'column',\n *     ]\n * );\n *\n * \/\/ Add index to existing table\n * $connection->addIndex(\"robots\", null, $index_unique);\n * $connection->addIndex(\"robots\", null, $index_primary);\n *```\n *",
        "file": "\/app\/phalcon\/Db\/Index.zep",
        "line": 42,
        "char": 5
    },
    {
        "type": "class",
        "name": "Index",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "IndexInterface",
                "file": "\/app\/phalcon\/Db\/Index.zep",
                "line": 43,
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
                    "name": "columns",
                    "docblock": "**\n     * Index columns\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 49,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Index.zep",
                    "line": 55,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "docblock": "**\n     * Index name\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 56,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Index.zep",
                    "line": 62,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * Index type\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 63,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Index.zep",
                    "line": 67,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 68,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "columns",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 68,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                "line": 68,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 68,
                            "char": 77
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
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 70,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 70,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 71,
                            "char": 11
                        },
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
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 71,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 71,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Index.zep",
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
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 72,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 72,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Db\\Index constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Index.zep",
                        "line": 69,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Index.zep",
                    "line": 68,
                    "last-line": 77,
                    "char": 19
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
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 78,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "indexName",
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 80,
                                    "char": 22
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 80,
                                    "char": 31
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 80,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 82,
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
                                            "value": "indexName",
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 82,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                                "line": 82,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                                "line": 82,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 82,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 82,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 82,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                "line": 82,
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
                                                    "value": "name parameter is required",
                                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                                    "line": 83,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                                "line": 83,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 83,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 84,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 86,
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
                                            "value": "columns",
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 86,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                                "line": 86,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                                "line": 86,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 86,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 86,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 86,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                "line": 86,
                                "char": 51
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
                                                    "value": "columns parameter is required",
                                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                                    "line": 87,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                                "line": 87,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 87,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 88,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 90,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 90,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 90,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 90,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 90,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 90,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                "line": 90,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "type",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                                "line": 91,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 91,
                                            "char": 24
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 92,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 97,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Index",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "indexName",
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 97,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 97,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "columns",
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 97,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 97,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Db\/Index.zep",
                                            "line": 97,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Index.zep",
                                        "line": 97,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                "line": 97,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Db\/Index.zep",
                            "line": 98,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Restore a Phalcon\\Db\\Index object from export\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "IndexInterface",
                                    "file": "\/app\/phalcon\/Db\/Index.zep",
                                    "line": 79,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Index.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Index.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Index.zep",
                    "line": 78,
                    "last-line": 99,
                    "char": 26
                }
            ],
            "file": "\/app\/phalcon\/Db\/Index.zep",
            "line": 42,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Index.zep",
        "line": 42,
        "char": 5
    }
]