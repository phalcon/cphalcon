[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Db adapters\n *",
        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "AdapterInterface",
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 21,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 21,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 21,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 21,
                            "char": 94
                        }
                    ],
                    "docblock": "**\n     * Adds a column to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 21,
                                "char": 103
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 21,
                        "char": 103
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 21,
                    "last-line": 25,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 26,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 26,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 26,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 26,
                            "char": 91
                        }
                    ],
                    "docblock": "**\n     * Adds an index to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 26,
                                "char": 100
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 26,
                        "char": 100
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 26,
                    "last-line": 30,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 31,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 31,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 31,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 31,
                            "char": 104
                        }
                    ],
                    "docblock": "**\n     * Adds a foreign key to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 31,
                                "char": 113
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 31,
                        "char": 113
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 31,
                    "last-line": 35,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 36,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 36,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 36,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 36,
                            "char": 96
                        }
                    ],
                    "docblock": "**\n     * Adds a primary key to a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 36,
                                "char": 105
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 36,
                        "char": 105
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 36,
                    "last-line": 41,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "affectedRows",
                    "docblock": "**\n     * Returns the number of affected rows by the last INSERT\/UPDATE\/DELETE\n     * reported by the database system\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 42,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 42,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 42,
                    "last-line": 46,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "begin",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "nesting",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 47,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 47,
                            "char": 46
                        }
                    ],
                    "docblock": "**\n     * Starts a transaction in the connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 47,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 47,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 47,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "close",
                    "docblock": "**\n     * Closes active connection returning success. Phalcon automatically closes\n     * and destroys active connections within Phalcon\\Db\\Pool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 53,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 53,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "commit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "nesting",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 58,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 58,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Commits the active transaction in the connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 58,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 58,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 58,
                    "last-line": 63,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "connect",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "descriptor",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 64,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 64,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * This method is automatically called in \\Phalcon\\Db\\Adapter\\Pdo\n     * constructor. Call it when you need to restore a database connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 64,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 64,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 64,
                    "last-line": 68,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 69,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Creates a new savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 69,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 69,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 69,
                    "last-line": 73,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 74,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 74,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 74,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Creates a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 74,
                                "char": 98
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 74,
                        "char": 98
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 74,
                    "last-line": 78,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 79,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 79,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 79,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 79,
                            "char": 93
                        }
                    ],
                    "docblock": "**\n     * Creates a view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 79,
                                "char": 102
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 79,
                        "char": 102
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 79,
                    "last-line": 83,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 84,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "whereCondition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 84,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 84,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 84,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 84,
                            "char": 84
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 84,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 84,
                            "char": 102
                        }
                    ],
                    "docblock": "**\n     * Deletes data from a table using custom RDBMS SQL syntax\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 84,
                                "char": 111
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 84,
                        "char": 111
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 84,
                    "last-line": 88,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 89,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 89,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 89,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Returns an array of Phalcon\\Db\\Column objects describing a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ColumnInterface",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 89,
                                    "char": 96
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 89,
                                "char": 96
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 89,
                        "char": 96
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 89,
                    "last-line": 93,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 94,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 94,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 94,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Lists table indexes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "IndexInterface",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 94,
                                    "char": 95
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 94,
                                "char": 95
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 94,
                        "char": 95
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 94,
                    "last-line": 98,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 99,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 99,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 99,
                            "char": 75
                        }
                    ],
                    "docblock": "**\n     * Lists table references\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ReferenceInterface",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 99,
                                    "char": 102
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 99,
                                "char": 102
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 99,
                        "char": 102
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 99,
                    "last-line": 103,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 104,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 104,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "columnName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 104,
                            "char": 88
                        }
                    ],
                    "docblock": "**\n     * Drops a column from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 104,
                                "char": 97
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 104,
                        "char": 97
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 104,
                    "last-line": 108,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 109,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 109,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "referenceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 109,
                            "char": 95
                        }
                    ],
                    "docblock": "**\n     * Drops a foreign key from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 109,
                                "char": 104
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 109,
                        "char": 104
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 109,
                    "last-line": 113,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 114,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 114,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "indexName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 114,
                            "char": 86
                        }
                    ],
                    "docblock": "**\n     * Drop an index from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 114,
                                "char": 95
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 114,
                        "char": 95
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 114,
                    "last-line": 118,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 119,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 119,
                            "char": 73
                        }
                    ],
                    "docblock": "**\n     * Drops primary key from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 119,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 119,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 119,
                    "last-line": 123,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 124,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 124,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 124,
                            "char": 75
                        },
                        {
                            "type": "parameter",
                            "name": "ifExists",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 124,
                                "char": 97
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 124,
                            "char": 97
                        }
                    ],
                    "docblock": "**\n     * Drops a table from a schema\/database\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 124,
                                "char": 106
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 124,
                        "char": 106
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 124,
                    "last-line": 128,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 129,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 129,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 129,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "ifExists",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 129,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 129,
                            "char": 95
                        }
                    ],
                    "docblock": "**\n     * Drops a view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 129,
                                "char": 104
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 129,
                        "char": 104
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 129,
                    "last-line": 133,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeIdentifier",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "identifier",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 134,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Escapes a column\/table\/schema name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 134,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 134,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 134,
                    "last-line": 138,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeString",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "str",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 139,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Escapes a value to avoid SQL injections\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 139,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 139,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 139,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "execute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlStatement",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 146,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 146,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 146,
                            "char": 74
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 146,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 146,
                            "char": 96
                        }
                    ],
                    "docblock": "**\n     * Sends SQL statements to the database server returning the success state.\n     * Use this method only when the SQL statement sent to the server doesn't\n     * return any rows\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 146,
                                "char": 105
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 146,
                        "char": 105
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 146,
                    "last-line": 150,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetchAll",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 151,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "fetchMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "2",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 151,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 151,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 151,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 151,
                            "char": 86
                        }
                    ],
                    "docblock": "**\n     * Dumps the complete result of a query into an array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 151,
                                "char": 96
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 151,
                        "char": 96
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 151,
                    "last-line": 168,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetchColumn",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 169,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 169,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 169,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 169,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 169,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Returns the n'th field of first row in a SQL query result\n     *\n     *```php\n     * \/\/ Getting count of robots\n     * $robotsCount = $connection->fetchColumn(\"SELECT count(*) FROM robots\");\n     * print_r($robotsCount);\n     *\n     * \/\/ Getting name of last edited robot\n     * $robot = $connection->fetchColumn(\n     *     \"SELECT id, name FROM robots order by modified desc\",\n     *     1\n     * );\n     * print_r($robot);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 169,
                                "char": 101
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 169,
                                "char": 107
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 169,
                        "char": 107
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 169,
                    "last-line": 173,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetchOne",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 174,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "fetchMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "2",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 174,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 174,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 174,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 174,
                            "char": 86
                        }
                    ],
                    "docblock": "**\n     * Returns the first row in a SQL query result\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 174,
                                "char": 96
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 174,
                        "char": 96
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 174,
                    "last-line": 178,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 179,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 179,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 179,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 179,
                    "last-line": 183,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 184,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 184,
                            "char": 65
                        }
                    ],
                    "docblock": "**\n     * Returns the SQL column definition from a column\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 184,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 184,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 184,
                    "last-line": 188,
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
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 189,
                            "char": 49
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 189,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 189,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 189,
                    "last-line": 193,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnectionId",
                    "docblock": "**\n     * Gets the active connection unique identifier\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 194,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 194,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 194,
                    "last-line": 198,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDescriptor",
                    "docblock": "**\n     * Return descriptor used to connect to the active database\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 199,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 199,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 199,
                    "last-line": 203,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDialect",
                    "docblock": "**\n     * Returns internal dialect instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DialectInterface",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 204,
                                    "char": 55
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 204,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 204,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 204,
                    "last-line": 208,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDialectType",
                    "docblock": "**\n     * Returns the name of the dialect used\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 209,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 209,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 209,
                    "last-line": 213,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultIdValue",
                    "docblock": "**\n     * Return the default identity value to insert in an identity column\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RawValue",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 214,
                                    "char": 54
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 214,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 214,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 214,
                    "last-line": 218,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getInternalHandler",
                    "docblock": "**\n     * Return internal PDO handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "\\Pdo",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 219,
                                    "char": 51
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 219,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 219,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 219,
                    "last-line": 223,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNestedTransactionSavepointName",
                    "docblock": "**\n     * Returns the savepoint name to use for nested transactions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 224,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 224,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 224,
                    "last-line": 228,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRealSQLStatement",
                    "docblock": "**\n     * Active SQL statement in the object without replace bound parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 229,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 229,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 229,
                    "last-line": 233,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSQLStatement",
                    "docblock": "**\n     * Active SQL statement in the object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 234,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 234,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 234,
                    "last-line": 238,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSQLBindTypes",
                    "docblock": "**\n     * Active SQL statement in the object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 239,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 239,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 239,
                    "last-line": 243,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSQLVariables",
                    "docblock": "**\n     * Active SQL statement in the object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 244,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 244,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 244,
                    "last-line": 248,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "docblock": "**\n     * Returns type of database system the adapter is used for\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 249,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 249,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 249,
                    "last-line": 253,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "insert",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 254,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 254,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 254,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 254,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 254,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 254,
                            "char": 88
                        }
                    ],
                    "docblock": "**\n     * Inserts data into a table using custom RDBMS SQL syntax\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 254,
                                "char": 97
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 254,
                        "char": 97
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 254,
                    "last-line": 272,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "insertAsDict",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 273,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 273,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 273,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 273,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Inserts data into a table using custom RBDM SQL syntax\n     *\n     * ```php\n     * \/\/ Inserting a new robot\n     * $success = $connection->insertAsDict(\n     *     \"robots\",\n     *     [\n     *         \"name\" => \"Astro Boy\",\n     *         \"year\" => 1952,\n     *     ]\n     * );\n     *\n     * \/\/ Next SQL sentence is sent to the database system\n     * INSERT INTO `robots` (`name`, `year`) VALUES (\"Astro boy\", 1952);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 273,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 273,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 273,
                    "last-line": 277,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isNestedTransactionsWithSavepoints",
                    "docblock": "**\n     * Returns if nested transactions should use savepoints\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 278,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 278,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 278,
                    "last-line": 282,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUnderTransaction",
                    "docblock": "**\n     * Checks whether connection is under database transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 283,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 283,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 283,
                    "last-line": 288,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "lastInsertId",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sequenceName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 289,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 289,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Returns insert id for the auto_increment column inserted in the last SQL\n     * statement\n     *",
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 289,
                    "last-line": 293,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 294,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "number",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 294,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Appends a LIMIT clause to sqlQuery argument\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 294,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 294,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 294,
                    "last-line": 298,
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
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 299,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 299,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * List all tables on a database\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 299,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 299,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 299,
                    "last-line": 303,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "listViews",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 304,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 304,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * List all views on a database\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 304,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 304,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 304,
                    "last-line": 308,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 309,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 309,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 309,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 309,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 309,
                                "char": 129
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 309,
                                "char": 137
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 309,
                            "char": 137
                        }
                    ],
                    "docblock": "**\n     * Modifies a table column based on a definition\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 309,
                                "char": 146
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 309,
                        "char": 146
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 309,
                    "last-line": 315,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "query",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlStatement",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 316,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 316,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 316,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 316,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 316,
                            "char": 94
                        }
                    ],
                    "docblock": "**\n     * Sends SQL statements to the database server returning the success state.\n     * Use this method only when the SQL statement sent to the server returns\n     * rows\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultInterface",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 316,
                                    "char": 117
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 316,
                                "char": 117
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 316,
                                "char": 123
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 316,
                        "char": 123
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 316,
                    "last-line": 320,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 321,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Releases given savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 321,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 321,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 321,
                    "last-line": 325,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rollback",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "nesting",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 326,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 326,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Rollbacks the active transaction in the connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 326,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 326,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 326,
                    "last-line": 330,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 331,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Rollbacks given savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 331,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 331,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 331,
                    "last-line": 335,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 336,
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
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 336,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 336,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 336,
                    "last-line": 340,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setNestedTransactionsWithSavepoints",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "nestedTransactionsWithSavepoints",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 341,
                            "char": 94
                        }
                    ],
                    "docblock": "**\n     * Set if nested transactions should use savepoints\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                    "line": 341,
                                    "char": 117
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 341,
                                "char": 117
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 341,
                        "char": 117
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 341,
                    "last-line": 346,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "supportSequences",
                    "docblock": "**\n     * Check whether the database system requires a sequence to produce\n     * auto-numeric values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 347,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 347,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 347,
                    "last-line": 351,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 352,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 352,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 352,
                            "char": 77
                        }
                    ],
                    "docblock": "**\n     * Generates SQL checking for the existence of a schema.table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 352,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 352,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 352,
                    "last-line": 356,
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
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 357,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 357,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 357,
                            "char": 77
                        }
                    ],
                    "docblock": "**\n     * Gets creation options from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 357,
                                "char": 87
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 357,
                        "char": 87
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 357,
                    "last-line": 361,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "update",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 362,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 362,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 362,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "whereCondition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 362,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 362,
                            "char": 79
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 362,
                                "char": 97
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 362,
                            "char": 97
                        }
                    ],
                    "docblock": "**\n     * Updates data on a table using custom RDBMS SQL syntax\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 362,
                                "char": 106
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 362,
                        "char": 106
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 362,
                    "last-line": 381,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "updateAsDict",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 382,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 382,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "whereCondition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 382,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 382,
                            "char": 83
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 382,
                                "char": 105
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 382,
                            "char": 105
                        }
                    ],
                    "docblock": "**\n     * Updates data on a table using custom RBDM SQL syntax\n     * Another, more convenient syntax\n     *\n     * ```php\n     * \/\/ Updating existing robot\n     * $success = $connection->updateAsDict(\n     *     \"robots\",\n     *     [\n     *         \"name\" => \"New Astro Boy\",\n     *     ],\n     *     \"id = 101\"\n     * );\n     *\n     * \/\/ Next SQL sentence is sent to the database system\n     * UPDATE `robots` SET `name` = \"Astro boy\" WHERE id = 101\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 382,
                                "char": 114
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 382,
                        "char": 114
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 382,
                    "last-line": 387,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useExplicitIdValue",
                    "docblock": "**\n     * Check whether the database system requires an explicit value for identity\n     * columns\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 388,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 388,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 388,
                    "last-line": 392,
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
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 393,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 393,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                            "line": 393,
                            "char": 75
                        }
                    ],
                    "docblock": "**\n     * Generates SQL checking for the existence of a schema.view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                                "line": 393,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                        "line": 393,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
                    "line": 393,
                    "last-line": 394,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
            "line": 394,
            "char": 1
        },
        "file": "\/app\/phalcon\/Db\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]