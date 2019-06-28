[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ColumnInterface",
                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ReferenceInterface",
                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\IndexInterface",
                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                "line": 15,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Db dialects\n *",
        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "DialectInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addColumn",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 25,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 25,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 25,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 25,
                            "char": 94
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to add a column to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 25,
                                "char": 105
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 25,
                        "char": 105
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addForeignKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 30,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 30,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "reference",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ReferenceInterface",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 30,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 30,
                            "char": 104
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to add an index to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 30,
                                "char": 115
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 30,
                        "char": 115
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addIndex",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 35,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 35,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "IndexInterface",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 35,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 35,
                            "char": 91
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to add an index to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 35,
                                "char": 102
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 35,
                        "char": 102
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addPrimaryKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 40,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 40,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "IndexInterface",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 40,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 40,
                            "char": 96
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to add the primary key to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 40,
                                "char": 107
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 40,
                        "char": 107
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 40,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createSavepoint",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 45,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Generate SQL to create a new savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 45,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 45,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 45,
                    "last-line": 49,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createTable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 50,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 50,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 50,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to create a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 50,
                                "char": 100
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 50,
                        "char": 100
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 50,
                    "last-line": 54,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createView",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "viewName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 55,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 55,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 55,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 55,
                            "char": 93
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to create a view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 55,
                                "char": 104
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 55,
                        "char": 104
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 55,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "describeColumns",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 60,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 60,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 60,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to describe a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 60,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 60,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 60,
                    "last-line": 64,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "describeIndexes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 65,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 65,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 65,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to query indexes on a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 65,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 65,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 65,
                    "last-line": 69,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "describeReferences",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 70,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 70,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 70,
                            "char": 75
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to query foreign keys on a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 70,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 70,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 70,
                    "last-line": 74,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dropColumn",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 75,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 75,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "columnName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 75,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to delete a column from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 75,
                                "char": 100
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 75,
                        "char": 100
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 75,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dropForeignKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 80,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 80,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "referenceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 80,
                            "char": 96
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to delete a foreign key from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 80,
                                "char": 107
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 80,
                        "char": 107
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 80,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dropIndex",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 85,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 85,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "indexName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 85,
                            "char": 87
                        }
                    ],
                    "docblock": "**\n      * Generates SQL to delete an index from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 85,
                                "char": 98
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 85,
                        "char": 98
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 85,
                    "last-line": 89,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dropPrimaryKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 90,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 90,
                            "char": 73
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to delete primary key from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 90,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 90,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 90,
                    "last-line": 94,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dropTable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 95,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 95,
                            "char": 68
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to drop a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 95,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 95,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 95,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dropView",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "viewName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 100,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 100,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 100,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "ifExists",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 100,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 100,
                            "char": 95
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to drop a view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 100,
                                "char": 106
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 100,
                        "char": 106
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 100,
                    "last-line": 104,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "forUpdate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 105,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Returns a SQL modified with a FOR UPDATE clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 105,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 105,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 105,
                    "last-line": 109,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnDefinition",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 110,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 110,
                            "char": 65
                        }
                    ],
                    "docblock": "**\n     * Gets the column name in RDBMS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 110,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 110,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 110,
                    "last-line": 114,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnList",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "columnList",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 115,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Gets a list of columns\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 115,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 115,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 115,
                    "last-line": 119,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCustomFunctions",
                    "docblock": "**\n     * Returns registered functions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 120,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 120,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 120,
                    "last-line": 125,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSqlExpression",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 126,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 126,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 126,
                            "char": 81
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 126,
                                "char": 100
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 126,
                            "char": 100
                        }
                    ],
                    "docblock": "**\n     * Transforms an intermediate representation for an expression into a\n     * database system valid expression\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 126,
                                "char": 111
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 126,
                        "char": 111
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 126,
                    "last-line": 130,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "limit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 131,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "number",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 131,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Generates the SQL for LIMIT clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 131,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 131,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 131,
                    "last-line": 135,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "listTables",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 136,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 136,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * List all tables in database\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 136,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 136,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 136,
                    "last-line": 140,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "modifyColumn",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 141,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 141,
                            "char": 71
                        },
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 141,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 141,
                            "char": 97
                        },
                        {
                            "type": "parameter",
                            "name": "currentColumn",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 141,
                                "char": 129
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 141,
                                "char": 137
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 141,
                            "char": 137
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to modify a column in a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 141,
                                "char": 148
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 141,
                        "char": 148
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 141,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerCustomFunction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 146,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "customFunction",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 146,
                            "char": 80
                        }
                    ],
                    "docblock": "**\n     * Registers custom SQL functions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Dialect",
                                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                    "line": 146,
                                    "char": 94
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 146,
                                "char": 94
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 146,
                        "char": 94
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 146,
                    "last-line": 150,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "releaseSavepoint",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 151,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Generate SQL to release a savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 151,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 151,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 151,
                    "last-line": 155,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rollbackSavepoint",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 156,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Generate SQL to rollback a savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 156,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 156,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 156,
                    "last-line": 160,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "select",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 161,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Builds a SELECT statement\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 161,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 161,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 161,
                    "last-line": 165,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sharedLock",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 166,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Returns a SQL modified with a LOCK IN SHARE MODE clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 166,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 166,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 166,
                    "last-line": 170,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "supportsReleaseSavepoints",
                    "docblock": "**\n     * Checks whether the platform supports releasing savepoints.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 171,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 171,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 171,
                    "last-line": 175,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "supportsSavepoints",
                    "docblock": "**\n     * Checks whether the platform supports savepoints\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 176,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 176,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 176,
                    "last-line": 180,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "tableExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 181,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 181,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 181,
                            "char": 76
                        }
                    ],
                    "docblock": "**\n     * Generates SQL checking for the existence of a schema.table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 181,
                                "char": 87
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 181,
                        "char": 87
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 181,
                    "last-line": 185,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "tableOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 186,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 186,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 186,
                            "char": 69
                        }
                    ],
                    "docblock": "**\n     * Generates the SQL to describe the table creation options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 186,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 186,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 186,
                    "last-line": 190,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "viewExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "viewName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 191,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 191,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                            "line": 191,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Generates SQL checking for the existence of a schema.view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                                "line": 191,
                                "char": 85
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                        "line": 191,
                        "char": 85
                    },
                    "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
                    "line": 191,
                    "last-line": 192,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
            "line": 192,
            "char": 1
        },
        "file": "\/app\/phalcon\/Db\/DialectInterface.zep",
        "line": 0,
        "char": 0
    }
]