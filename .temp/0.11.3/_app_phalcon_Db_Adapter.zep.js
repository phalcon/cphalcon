[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db",
                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ColumnInterface",
                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                "line": 15,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                "line": 16,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Base class for Phalcon\\Db adapters\n *",
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 21,
        "char": 8
    },
    {
        "type": "class",
        "name": "Adapter",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "AdapterInterface",
                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                "line": 21,
                "char": 51
            },
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                "line": 22,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "connectionConsecutive",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 26,
                        "char": 47
                    },
                    "docblock": "**\n     * Connection ID\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 32,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "connectionId",
                    "docblock": "**\n     * Active connection ID\n     *\n     * @var long\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 37,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "descriptor",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 38,
                        "char": 30
                    },
                    "docblock": "**\n     * Descriptor used to connect to a database\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 42,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "dialect",
                    "docblock": "**\n     * Dialect instance\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 49,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "dialectType",
                    "docblock": "**\n     * Name of the dialect used\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 50,
                            "char": 33
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 56,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "docblock": "**\n     * Event Manager\n     *\n     * @var Phalcon\\Events\\Manager\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 63,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sqlBindTypes",
                    "docblock": "**\n     * Active SQL Bind Types\n     *\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 70,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sqlStatement",
                    "docblock": "**\n     * Active SQL Statement\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 77,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sqlVariables",
                    "docblock": "**\n     * Active SQL bound parameter variables\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 78,
                            "char": 34
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 82,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "transactionLevel",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 83,
                        "char": 35
                    },
                    "docblock": "**\n     * Current transaction level\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 87,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "transactionsWithSavepoints",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 88,
                        "char": 49
                    },
                    "docblock": "**\n     * Whether the database supports transactions with save points\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 94,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * Type of database system the adapter is used for\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 95,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 99,
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
                            "name": "descriptor",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 100,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dialectClass",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 102,
                                    "char": 25
                                },
                                {
                                    "variable": "connectionId",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 102,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 104,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connectionId",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 104,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "connectionConsecutive",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 104,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 104,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 104,
                                    "char": 55
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "connectionId",
                                    "expr": {
                                        "type": "variable",
                                        "value": "connectionId",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 105,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 105,
                                    "char": 46
                                },
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "connectionConsecutive",
                                    "expr": {
                                        "type": "add",
                                        "left": {
                                            "type": "variable",
                                            "value": "connectionId",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 106,
                                            "char": 56
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 106,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 106,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 106,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 111,
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
                                        "value": "dialectClass",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 111,
                                        "char": 58
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "descriptor",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 111,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "dialectClass",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 111,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 111,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 111,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 111,
                                "char": 58
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "dialectClass",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "phalcon\\\\db\\\\dialect\\\\",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 112,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 112,
                                                        "char": 62
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "dialectType",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 112,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 112,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 112,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 112,
                                            "char": 74
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 113,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 118,
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
                                        "value": "dialectClass",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 118,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 118,
                                    "char": 33
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 118,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 118,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "dialect",
                                            "expr": {
                                                "type": "new",
                                                "class": "dialectClass",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 119,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 119,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "dialectClass",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 120,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 120,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 120,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 120,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "dialect",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "dialectClass",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 121,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 121,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 122,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 124,
                                    "char": 11
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 124,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "descriptor",
                                    "expr": {
                                        "type": "variable",
                                        "value": "descriptor",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 124,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 124,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 125,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Db\\Adapter constructor\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 100,
                    "last-line": 129,
                    "char": 19
                },
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 130,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 130,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 130,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 130,
                            "char": 94
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 132,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 133,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 133,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 133,
                                                "char": 27
                                            },
                                            "name": "addColumn",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 134,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 134,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 135,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 135,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 137,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 137,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 138,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 138,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 138,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 139,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 131,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 131,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 130,
                    "last-line": 143,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 144,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 144,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 144,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 144,
                            "char": 104
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 146,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 147,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 147,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 147,
                                                "char": 27
                                            },
                                            "name": "addForeignKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 148,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 148,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 149,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 149,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "reference",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 151,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 151,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 152,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 152,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 152,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 153,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 145,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 145,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 144,
                    "last-line": 157,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 158,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 158,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 158,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 158,
                            "char": 91
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 160,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 161,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 161,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 161,
                                                "char": 27
                                            },
                                            "name": "addIndex",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 162,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 162,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 163,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 163,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "index",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 165,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 165,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 166,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 166,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 166,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 167,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 159,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 158,
                    "last-line": 171,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 172,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 172,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 172,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 172,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 174,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 175,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 175,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 175,
                                                "char": 27
                                            },
                                            "name": "addPrimaryKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 176,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 176,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 177,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 177,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "index",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 179,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 179,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 180,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 180,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 180,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 181,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 173,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 173,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 172,
                    "last-line": 185,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 186,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dialect",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 188,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 190,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dialect",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 190,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "dialect",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 190,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 190,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 190,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 192,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dialect",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 192,
                                            "char": 30
                                        },
                                        "name": "supportsSavePoints",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 192,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 192,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 192,
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
                                                    "type": "string",
                                                    "value": "Savepoints are not supported by this database adapter.",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 195,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 195,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 195,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 196,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 198,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 198,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "dialect",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 199,
                                                "char": 21
                                            },
                                            "name": "createSavepoint",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 199,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 199,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 200,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 200,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 200,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 201,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 187,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 187,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 186,
                    "last-line": 205,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 206,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 206,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 206,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 208,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 210,
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
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 210,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 210,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 210,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 210,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 210,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 210,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 210,
                                "char": 57
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
                                                    "value": "The table must contain at least one column",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 211,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 211,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 211,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 212,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 214,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "columns",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 214,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 214,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 214,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 214,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 214,
                                "char": 37
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
                                                    "value": "The table must contain at least one column",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 215,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 215,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 215,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 216,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 218,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 218,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 219,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 219,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 219,
                                                "char": 27
                                            },
                                            "name": "createTable",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 220,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 220,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 221,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 221,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "definition",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 223,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 223,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 224,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 224,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 224,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 225,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 207,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 207,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 206,
                    "last-line": 229,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 230,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 230,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 230,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 230,
                            "char": 93
                        }
                    ],
                    "statements": [
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
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 232,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "sql",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 232,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 232,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 232,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 232,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 232,
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
                                                    "value": "The table must contain at least one column",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 233,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 233,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 233,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 234,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 236,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 236,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 237,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 237,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 237,
                                                "char": 27
                                            },
                                            "name": "createView",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "viewName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 238,
                                                        "char": 25
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 238,
                                                    "char": 25
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "definition",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 239,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 239,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 241,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 241,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 242,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 242,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 242,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 243,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 231,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 231,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 230,
                    "last-line": 258,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 259,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 259,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 259,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 259,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 259,
                            "char": 92
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 259,
                                "char": 114
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 259,
                            "char": 114
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 261,
                                    "char": 16
                                },
                                {
                                    "variable": "escapedTable",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 261,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 263,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escapedTable",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 263,
                                            "char": 33
                                        },
                                        "name": "escapeIdentifier",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 263,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 263,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 263,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 263,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 265,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sql",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "DELETE FROM ",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 265,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "escapedTable",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 265,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 265,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 265,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 267,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "whereCondition",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 267,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 267,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 267,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " WHERE ",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 268,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "whereCondition",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 268,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 268,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 268,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 269,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 274,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 274,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sql",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 274,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 274,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 274,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 274,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "dataTypes",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 274,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 274,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 274,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 275,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Deletes data from a table using custom RBDM SQL syntax\n     *\n     * ```php\n     * \/\/ Deleting existing robot\n     * $success = $connection->delete(\n     *     \"robots\",\n     *     \"id = 101\"\n     * );\n     *\n     * \/\/ Next SQL sentence is generated\n     * DELETE FROM `robots` WHERE `id` = 101\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 260,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 260,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 259,
                    "last-line": 285,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 286,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 286,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 286,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "indexes",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 288,
                                    "char": 20
                                },
                                {
                                    "variable": "index",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 288,
                                    "char": 27
                                },
                                {
                                    "variable": "keyName",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 288,
                                    "char": 36
                                },
                                {
                                    "variable": "indexObjects",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 288,
                                    "char": 50
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 288,
                                    "char": 56
                                },
                                {
                                    "variable": "indexColumns",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 288,
                                    "char": 70
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 288,
                                    "char": 79
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 290,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "indexes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 290,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 290,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 292,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 292,
                                    "char": 27
                                },
                                "name": "fetchAll",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 292,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 292,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 292,
                                                "char": 51
                                            },
                                            "name": "describeIndexes",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 292,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 292,
                                                    "char": 73
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schema",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 292,
                                                        "char": 81
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 292,
                                                    "char": 81
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 292,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 292,
                                        "char": 82
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Db",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 292,
                                                "char": 97
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "FETCH_NUM",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 292,
                                                "char": 97
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 292,
                                            "char": 97
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 292,
                                        "char": 97
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 292,
                                "char": 99
                            },
                            "value": "index",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "keyName",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 293,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 293,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 293,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 293,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 295,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "indexes",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 295,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "keyName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 295,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 295,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 295,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 295,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columns",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 296,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 296,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 297,
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
                                                    "variable": "columns",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "indexes",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 298,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "keyName",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 298,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 298,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 298,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 299,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 301,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "columns",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 301,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 301,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 301,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 301,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 302,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "indexes",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "keyName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 302,
                                                    "char": 32
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 302,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 302,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 303,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 305,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "indexObjects",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 305,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 305,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 307,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "indexes",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 307,
                                "char": 43
                            },
                            "key": "name",
                            "value": "indexColumns",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "indexObjects",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 311,
                                                    "char": 34
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "Index",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 311,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 311,
                                                        "char": 52
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "indexColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 311,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 311,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 311,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 311,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 312,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 314,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "indexObjects",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 314,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 315,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Lists table indexes\n     *\n     *```php\n     * print_r(\n     *     $connection->describeIndexes(\"robots_parts\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "IndexInterface",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 287,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 287,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 287,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 286,
                    "last-line": 325,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 326,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 326,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 326,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "references",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 328,
                                    "char": 23
                                },
                                {
                                    "variable": "reference",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 328,
                                    "char": 34
                                },
                                {
                                    "variable": "arrayReference",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 328,
                                    "char": 50
                                },
                                {
                                    "variable": "constraintName",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 328,
                                    "char": 66
                                },
                                {
                                    "variable": "referenceObjects",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 329,
                                    "char": 29
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 329,
                                    "char": 35
                                },
                                {
                                    "variable": "referencedSchema",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 329,
                                    "char": 53
                                },
                                {
                                    "variable": "referencedTable",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 329,
                                    "char": 70
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 329,
                                    "char": 79
                                },
                                {
                                    "variable": "referencedColumns",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 330,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 332,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "references",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 332,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 332,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 334,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 334,
                                    "char": 31
                                },
                                "name": "fetchAll",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 334,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 334,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 334,
                                                "char": 55
                                            },
                                            "name": "describeReferences",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 334,
                                                        "char": 80
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 334,
                                                    "char": 80
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schema",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 334,
                                                        "char": 88
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 334,
                                                    "char": 88
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 334,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 334,
                                        "char": 89
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Db",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 334,
                                                "char": 104
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "FETCH_NUM",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 334,
                                                "char": 104
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 334,
                                            "char": 104
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 334,
                                        "char": 104
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 334,
                                "char": 106
                            },
                            "value": "reference",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "constraintName",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "reference",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 335,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 335,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 335,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 335,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 337,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "references",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 337,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "constraintName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 337,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 337,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 337,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 337,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referencedSchema",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "reference",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 338,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "3",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 338,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 338,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 338,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 339,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referencedTable",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "reference",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 339,
                                                            "char": 48
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "4",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 339,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 339,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 339,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 340,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columns",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 340,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 340,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 341,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referencedColumns",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 341,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 341,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 342,
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
                                                    "variable": "referencedSchema",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "references",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 343,
                                                                "char": 50
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 343,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 343,
                                                            "char": 66
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedSchema",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 343,
                                                            "char": 83
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 343,
                                                        "char": 84
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 343,
                                                    "char": 84
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 344,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referencedTable",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "references",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 344,
                                                                "char": 49
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 344,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 344,
                                                            "char": 65
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 344,
                                                            "char": 81
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 344,
                                                        "char": 82
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 344,
                                                    "char": 82
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 345,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columns",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "references",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 345,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 345,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 345,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 345,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 345,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 345,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 346,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referencedColumns",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "references",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 346,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 346,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 346,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 346,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 346,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 346,
                                                    "char": 86
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 347,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 349,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "columns",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "reference",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 349,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 349,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 349,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 349,
                                            "char": 41
                                        },
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "referencedColumns",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "reference",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 350,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "5",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 350,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 350,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 350,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 352,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "references",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "constraintName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 352,
                                                    "char": 42
                                                }
                                            ],
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "referencedSchema",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 353,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedSchema",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 353,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 353,
                                                        "char": 53
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 354,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 354,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 354,
                                                        "char": 52
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 355,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 355,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 355,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 356,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 357,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 357,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 357,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 357,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 358,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 360,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "referenceObjects",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 360,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 360,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 362,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "references",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 362,
                                "char": 48
                            },
                            "key": "name",
                            "value": "arrayReference",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "referenceObjects",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 363,
                                                    "char": 38
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "Reference",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 364,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 364,
                                                        "char": 21
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "referencedSchema",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 366,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 366,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedSchema",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 366,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 366,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 366,
                                                                    "char": 73
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "referencedTable",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 367,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 367,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedTable",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 367,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 367,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 367,
                                                                    "char": 72
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "columns",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 368,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 368,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "columns",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 368,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 368,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 368,
                                                                    "char": 64
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "referencedColumns",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 369,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 369,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedColumns",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 369,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 370,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 370,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 371,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 371,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 371,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 371,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 372,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 374,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "referenceObjects",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 374,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 375,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Lists table references\n     *\n     *```php\n     * print_r(\n     *     $connection->describeReferences(\"robots_parts\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ReferenceInterface",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 327,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 327,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 327,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 326,
                    "last-line": 379,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 380,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 380,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "columnName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 380,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 382,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 383,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 383,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 383,
                                                "char": 27
                                            },
                                            "name": "dropColumn",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 384,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 384,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 385,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 385,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 387,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 387,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 388,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 388,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 388,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 389,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 381,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 381,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 380,
                    "last-line": 393,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 394,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 394,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "referenceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 394,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 396,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 397,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 397,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 397,
                                                "char": 27
                                            },
                                            "name": "dropForeignKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 398,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 398,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 399,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 399,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "referenceName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 401,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 401,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 402,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 402,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 402,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 403,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 395,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 395,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 394,
                    "last-line": 407,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 408,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 408,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "indexName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 408,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 410,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 411,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 411,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 411,
                                                "char": 27
                                            },
                                            "name": "dropIndex",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 412,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 412,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 413,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 413,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "indexName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 415,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 415,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 416,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 416,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 416,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 417,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 409,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 409,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 408,
                    "last-line": 421,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 422,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 422,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 424,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 425,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 425,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 425,
                                                "char": 27
                                            },
                                            "name": "dropPrimaryKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 426,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 426,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 428,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 428,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 429,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 429,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 429,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 430,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Drops a table's primary key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 423,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 423,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 422,
                    "last-line": 434,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 435,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 435,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 435,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 435,
                                "char": 97
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 435,
                            "char": 97
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 437,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 438,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 438,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 438,
                                                "char": 27
                                            },
                                            "name": "dropTable",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 439,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 439,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 440,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 440,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ifExists",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 442,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 442,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 443,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 443,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 443,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 444,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 436,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 436,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 435,
                    "last-line": 448,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 449,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 449,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 449,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 449,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 449,
                            "char": 95
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 451,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 452,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 452,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 452,
                                                "char": 27
                                            },
                                            "name": "dropView",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "viewName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 453,
                                                        "char": 25
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 453,
                                                    "char": 25
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 454,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 454,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ifExists",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 456,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 456,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 457,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 457,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 457,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 458,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 450,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 450,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 449,
                    "last-line": 475,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 476,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "identifier",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 478,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 478,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 478,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 478,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 479,
                                                        "char": 25
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "dialect",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 479,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 479,
                                                    "char": 34
                                                },
                                                "name": "escape",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "identifier",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 479,
                                                                "char": 52
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 479,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 479,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 479,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 479,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": ".",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 479,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 479,
                                            "char": 61
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 479,
                                                    "char": 68
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 479,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 479,
                                                "char": 77
                                            },
                                            "name": "escape",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "identifier",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 479,
                                                            "char": 95
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 479,
                                                            "char": 97
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 479,
                                                        "char": 98
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 479,
                                                    "char": 98
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 479,
                                            "char": 99
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 479,
                                        "char": 99
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 480,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 482,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 482,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 482,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 482,
                                    "char": 30
                                },
                                "name": "escape",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "identifier",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 482,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 482,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 482,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 483,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escapes a column\/table\/schema name\n     *\n     *```php\n     * $escapedTable = $connection->escapeIdentifier(\n     *     \"robots\"\n     * );\n     *\n     * $escapedTable = $connection->escapeIdentifier(\n     *     [\n     *         \"store\",\n     *         \"robots\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 477,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 477,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 476,
                    "last-line": 511,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 512,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "fetchMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "Db",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 512,
                                    "char": 78
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "FETCH_ASSOC",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 512,
                                    "char": 78
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 512,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 512,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 512,
                                "char": 101
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 512,
                            "char": 101
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 512,
                                "char": 123
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 512,
                            "char": 123
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 514,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 516,
                            "char": 11
                        },
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
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 516,
                                            "char": 27
                                        },
                                        "name": "query",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sqlQuery",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 516,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 516,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindParams",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 516,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 516,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindTypes",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 516,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 516,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 516,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 516,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 518,
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
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 518,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 518,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 518,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 518,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 519,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 520,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 522,
                            "char": 14
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 522,
                                    "char": 16
                                },
                                "name": "setFetchMode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fetchMode",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 522,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 522,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 522,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 524,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 524,
                                    "char": 23
                                },
                                "name": "fetchAll",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 524,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 525,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Dumps the complete result of a query into an array\n     *\n     *```php\n     * \/\/ Getting all robots with associative indexes only\n     * $robots = $connection->fetchAll(\n     *     \"SELECT * FROM robots\",\n     *     \\Phalcon\\Db::FETCH_ASSOC\n     * );\n     *\n     * foreach ($robots as $robot) {\n     *     print_r($robot);\n     * }\n     *\n     *  \/\/ Getting all robots that contains word \"robot\" withing the name\n     * $robots = $connection->fetchAll(\n     *     \"SELECT * FROM robots WHERE name LIKE :name\",\n     *     \\Phalcon\\Db::FETCH_ASSOC,\n     *     [\n     *         \"name\" => \"%robot%\",\n     *     ]\n     * );\n     * foreach($robots as $robot) {\n     *     print_r($robot);\n     * }\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 513,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 513,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 512,
                    "last-line": 542,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 543,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 543,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 543,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 543,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 543,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "row",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 545,
                                    "char": 16
                                },
                                {
                                    "variable": "columnValue",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 545,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 547,
                            "char": 11
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
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 547,
                                            "char": 24
                                        },
                                        "name": "fetchOne",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sqlQuery",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 547,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 547,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Db",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 547,
                                                        "char": 58
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "FETCH_BOTH",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 547,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 547,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 547,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "placeholders",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 547,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 547,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 547,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 547,
                                    "char": 73
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 549,
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
                                        "value": "columnValue",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 549,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "row",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 549,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 549,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 549,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 549,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 549,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 550,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 551,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 553,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "columnValue",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 553,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 554,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 543,
                                "char": 101
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 544,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 544,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 543,
                    "last-line": 571,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 572,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "fetchMode",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "Db",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 572,
                                    "char": 79
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "FETCH_ASSOC",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 572,
                                    "char": 79
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 572,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 572,
                            "char": 79
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 572,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 572,
                            "char": 102
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 572,
                                "char": 124
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 572,
                            "char": 124
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 574,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 576,
                            "char": 11
                        },
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
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 576,
                                            "char": 27
                                        },
                                        "name": "query",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sqlQuery",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 576,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 576,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindParams",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 576,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 576,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindTypes",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 576,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 576,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 576,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 576,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 578,
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
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 578,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 578,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 578,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 578,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 579,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 580,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 582,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "fetchMode",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 582,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 582,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 582,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "result",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 583,
                                            "char": 20
                                        },
                                        "name": "setFetchMode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fetchMode",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 583,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 583,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 583,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 584,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 586,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 586,
                                    "char": 23
                                },
                                "name": "fetch",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 586,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 587,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the first row in a SQL query result\n     *\n     *```php\n     * \/\/ Getting first robot\n     * $robot = $connection->fetchOne(\"SELECT * FROM robots\");\n     * print_r($robot);\n     *\n     * \/\/ Getting first robot with associative indexes only\n     * $robot = $connection->fetchOne(\n     *     \"SELECT * FROM robots\",\n     *     \\Phalcon\\Db::FETCH_ASSOC\n     * );\n     * print_r($robot);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 573,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 573,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 572,
                    "last-line": 591,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 592,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 594,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 594,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 594,
                                    "char": 30
                                },
                                "name": "forUpdate",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sqlQuery",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 594,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 594,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 594,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 595,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 593,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 593,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 592,
                    "last-line": 599,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 600,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 600,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 602,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 602,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 602,
                                    "char": 30
                                },
                                "name": "getColumnDefinition",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 602,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 602,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 602,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 603,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 601,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 601,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 600,
                    "last-line": 607,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 608,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 610,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 610,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 610,
                                    "char": 30
                                },
                                "name": "getColumnList",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "columnList",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 610,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 610,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 610,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 611,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 609,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 609,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 608,
                    "last-line": 615,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnectionId",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 618,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "connectionId",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 618,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 618,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 619,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the active connection unique identifier\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 617,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 617,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 616,
                    "last-line": 640,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultIdValue",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "RawValue",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "null",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 643,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 643,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 643,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 644,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default identity value to be inserted in an identity column\n     *\n     *```php\n     * \/\/ Inserting a new robot with a valid default value for the column 'id'\n     * $success = $connection->insert(\n     *     \"robots\",\n     *     [\n     *         $connection->getDefaultIdValue(),\n     *         \"Astro Boy\",\n     *         1952,\n     *     ],\n     *     [\n     *         \"id\",\n     *         \"name\",\n     *         \"year\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RawValue",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 642,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 642,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 642,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 641,
                    "last-line": 664,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultValue",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "RawValue",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "DEFAULT",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 667,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 667,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 667,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 668,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default value to make the RBDM use the default value declared\n     * in the table definition\n     *\n     *```php\n     * \/\/ Inserting a new robot with a valid default value for the column 'year'\n     * $success = $connection->insert(\n     *     \"robots\",\n     *     [\n     *         \"Astro Boy\",\n     *         $connection->getDefaultValue()\n     *     ],\n     *     [\n     *         \"name\",\n     *         \"year\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RawValue",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 666,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 666,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 666,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 665,
                    "last-line": 672,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDescriptor",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 675,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "descriptor",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 675,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 675,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 676,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return descriptor used to connect to the active database\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 674,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 674,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 673,
                    "last-line": 680,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDialect",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 683,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "dialect",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 683,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 683,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 684,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns internal dialect instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DialectInterface",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 682,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 682,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 682,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 681,
                    "last-line": 688,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 691,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 691,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 691,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 692,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 690,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 690,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 690,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 689,
                    "last-line": 696,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNestedTransactionSavepointName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "PHALCON_SAVEPOINT_",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 699,
                                    "char": 35
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 699,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "transactionLevel",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 699,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 699,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 699,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 700,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the savepoint name to use for nested transactions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 698,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 698,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 697,
                    "last-line": 704,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRealSQLStatement",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 707,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "sqlStatement",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 707,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 707,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 708,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Active SQL statement in the object without replace bound parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 706,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 706,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 705,
                    "last-line": 712,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSQLBindTypes",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 715,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "sqlBindTypes",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 715,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 715,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 716,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Active SQL statement in the object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 714,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 714,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 713,
                    "last-line": 720,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSQLStatement",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 723,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "sqlStatement",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 723,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 723,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 724,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Active SQL statement in the object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 722,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 722,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 721,
                    "last-line": 740,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 741,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 741,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 741,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 741,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 741,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 741,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "placeholders",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 743,
                                    "char": 25
                                },
                                {
                                    "variable": "insertValues",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 743,
                                    "char": 39
                                },
                                {
                                    "variable": "bindDataTypes",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 743,
                                    "char": 54
                                },
                                {
                                    "variable": "bindType",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 743,
                                    "char": 64
                                },
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 743,
                                    "char": 74
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 744,
                                    "char": 18
                                },
                                {
                                    "variable": "escapedTable",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 744,
                                    "char": 32
                                },
                                {
                                    "variable": "joinedValues",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 744,
                                    "char": 46
                                },
                                {
                                    "variable": "escapedFields",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 744,
                                    "char": 61
                                },
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 744,
                                    "char": 68
                                },
                                {
                                    "variable": "insertSql",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 744,
                                    "char": 79
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 749,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "values",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 749,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 749,
                                                "char": 34
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 749,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 749,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 749,
                                "char": 36
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Unable to insert into ",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 751,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "table",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 751,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 751,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " without data",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 752,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 752,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 752,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 752,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 753,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 755,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "placeholders",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 755,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 755,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "insertValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 756,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 756,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 758,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "bindDataTypes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 758,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 758,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 764,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "values",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 764,
                                "char": 39
                            },
                            "key": "position",
                            "value": "value",
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
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 765,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 765,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 765,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 765,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 765,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "RawValue",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 765,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 765,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 765,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "placeholders",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "string",
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 766,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 766,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 766,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 767,
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
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 768,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 768,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 768,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 768,
                                                "char": 43
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "value",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "string",
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 769,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 769,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 769,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 770,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 772,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 772,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 772,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 772,
                                                "char": 35
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "placeholders",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "null",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 773,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 773,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 774,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "placeholders",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "?",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 775,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 775,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 776,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "insertValues",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 776,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 776,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 778,
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
                                                                "value": "dataTypes",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 778,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 778,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 778,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 778,
                                                        "char": 50
                                                    },
                                                    "statements": [
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
                                                                            "value": "bindType",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 779,
                                                                            "char": 74
                                                                        },
                                                                        "right": {
                                                                            "type": "array-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "dataTypes",
                                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                "line": 779,
                                                                                "char": 63
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "position",
                                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                "line": 779,
                                                                                "char": 72
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 779,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 779,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 779,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 779,
                                                                "char": 74
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
                                                                                    "value": "Incomplete number of bind types",
                                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                    "line": 782,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                "line": 782,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 782,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 783,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 785,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable-append",
                                                                    "operator": "assign",
                                                                    "variable": "bindDataTypes",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "bindType",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 785,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 785,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 786,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 787,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 788,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 789,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 791,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escapedTable",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 791,
                                            "char": 33
                                        },
                                        "name": "escapeIdentifier",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 791,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 791,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 791,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 791,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 796,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "joinedValues",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "join",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ", ",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 796,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 796,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "placeholders",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 796,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 796,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 796,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 796,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 798,
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
                                        "value": "fields",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 798,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 798,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 798,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 798,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escapedFields",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 799,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 799,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 801,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "fields",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 801,
                                        "char": 33
                                    },
                                    "value": "field",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "escapedFields",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 802,
                                                            "char": 44
                                                        },
                                                        "name": "escapeIdentifier",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "field",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 802,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 802,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 802,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 802,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 803,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 805,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "insertSql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "INSERT INTO ",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 805,
                                                                        "char": 42
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "escapedTable",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 805,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 805,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": " (",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 805,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 805,
                                                                "char": 62
                                                            },
                                                            "right": {
                                                                "type": "fcall",
                                                                "name": "join",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": ", ",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 805,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 805,
                                                                        "char": 71
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "escapedFields",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 805,
                                                                            "char": 86
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 805,
                                                                        "char": 86
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 805,
                                                                "char": 88
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 805,
                                                            "char": 88
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ") VALUES (",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 805,
                                                            "char": 101
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 805,
                                                        "char": 101
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "joinedValues",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 805,
                                                        "char": 116
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 805,
                                                    "char": 116
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 805,
                                                    "char": 119
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 805,
                                                "char": 119
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 805,
                                            "char": 119
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 806,
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
                                            "variable": "insertSql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "INSERT INTO ",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 807,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "escapedTable",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 807,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 807,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": " VALUES (",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 807,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 807,
                                                        "char": 69
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "joinedValues",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 807,
                                                        "char": 84
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 807,
                                                    "char": 84
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 807,
                                                    "char": 87
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 807,
                                                "char": 87
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 807,
                                            "char": 87
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 808,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 813,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "bindDataTypes",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 813,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 813,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 813,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 813,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 814,
                                            "char": 25
                                        },
                                        "name": "execute",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "insertSql",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 814,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 814,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "insertValues",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 814,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 814,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 814,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 815,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 817,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 817,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "insertSql",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 817,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 817,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "insertValues",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 817,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 817,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "bindDataTypes",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 817,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 817,
                                        "char": 70
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 817,
                                "char": 71
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 818,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Inserts data into a table using custom RDBMS SQL syntax\n     *\n     * ```php\n     * \/\/ Inserting a new robot\n     * $success = $connection->insert(\n     *     \"robots\",\n     *     [\"Astro Boy\", 1952],\n     *     [\"name\", \"year\"]\n     * );\n     *\n     * \/\/ Next SQL sentence is sent to the database system\n     * INSERT INTO `robots` (`name`, `year`) VALUES (\"Astro boy\", 1952);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 742,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 742,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 741,
                    "last-line": 836,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 837,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 837,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 837,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 837,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "values",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 839,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 839,
                                    "char": 24
                                },
                                {
                                    "variable": "fields",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 839,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 839,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 840,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 840,
                                    "char": 18
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 840,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 842,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 842,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 842,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 842,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 842,
                                    "char": 34
                                },
                                "right": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 842,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 842,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 842,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 843,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 844,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 846,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 846,
                                "char": 34
                            },
                            "key": "field",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "fields",
                                            "expr": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 847,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 847,
                                            "char": 33
                                        },
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "values",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 848,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 848,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 849,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 851,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 851,
                                    "char": 21
                                },
                                "name": "insert",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "table",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 851,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 851,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "values",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 851,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 851,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fields",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 851,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 851,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "dataTypes",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 851,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 851,
                                        "char": 61
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 851,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 852,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 838,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 838,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 837,
                    "last-line": 856,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isNestedTransactionsWithSavepoints",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 859,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "transactionsWithSavepoints",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 859,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 859,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 860,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns if nested transactions should use savepoints\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 858,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 858,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 857,
                    "last-line": 868,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 869,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "number",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 869,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 871,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 871,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 871,
                                    "char": 30
                                },
                                "name": "limit",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sqlQuery",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 871,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 871,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "number",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 871,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 871,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 871,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 872,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Appends a LIMIT clause to $sqlQuery argument\n     *\n     * ```php\n     * echo $connection->limit(\"SELECT * FROM robots\", 5);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 870,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 870,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 869,
                    "last-line": 882,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 883,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 883,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "tables",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 885,
                                    "char": 19
                                },
                                {
                                    "variable": "table",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 885,
                                    "char": 26
                                },
                                {
                                    "variable": "allTables",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 885,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 887,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "allTables",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 887,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 887,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 889,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "tables",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 889,
                                            "char": 27
                                        },
                                        "name": "fetchAll",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 890,
                                                            "char": 18
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "dialect",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 890,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 890,
                                                        "char": 27
                                                    },
                                                    "name": "listTables",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "schemaName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 890,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 890,
                                                            "char": 49
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 890,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 890,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Db",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 892,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "FETCH_NUM",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 892,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 892,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 892,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 892,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 892,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 894,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "tables",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 894,
                                "char": 29
                            },
                            "value": "table",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "allTables",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 895,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 895,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 895,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 895,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 896,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 898,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "allTables",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 898,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 899,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * List all tables on a database\n     *\n     *```php\n     * print_r(\n     *     $connection->listTables(\"blog\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 884,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 884,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 883,
                    "last-line": 909,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 910,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 910,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "tables",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 912,
                                    "char": 19
                                },
                                {
                                    "variable": "table",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 912,
                                    "char": 26
                                },
                                {
                                    "variable": "allTables",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 912,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 914,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "allTables",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 914,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 914,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 916,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "tables",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 916,
                                            "char": 27
                                        },
                                        "name": "fetchAll",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 917,
                                                            "char": 18
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "dialect",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 917,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 917,
                                                        "char": 27
                                                    },
                                                    "name": "listViews",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "schemaName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 917,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 917,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 917,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 917,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Db",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 919,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "FETCH_NUM",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 919,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 919,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 919,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 919,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 919,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 921,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "tables",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 921,
                                "char": 29
                            },
                            "value": "table",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "allTables",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 922,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 922,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 922,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 922,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 923,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 925,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "allTables",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 925,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 926,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * List all views on a database\n     *\n     *```php\n     * print_r(\n     *     $connection->listViews(\"blog\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 911,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 911,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 910,
                    "last-line": 930,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 931,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 931,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 931,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 931,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 931,
                                "char": 129
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 931,
                                "char": 137
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 931,
                            "char": 137
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 933,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 934,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 934,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 934,
                                                "char": 27
                                            },
                                            "name": "modifyColumn",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 935,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 935,
                                                    "char": 26
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 936,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 936,
                                                    "char": 27
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 937,
                                                        "char": 23
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 937,
                                                    "char": 23
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "currentColumn",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 939,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 939,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 940,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 940,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 940,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 941,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 932,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 932,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 931,
                    "last-line": 945,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 946,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dialect",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 948,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 950,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dialect",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 950,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "dialect",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 950,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 950,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 950,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 952,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dialect",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 952,
                                            "char": 30
                                        },
                                        "name": "supportsSavePoints",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 952,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 952,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 952,
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
                                                    "type": "string",
                                                    "value": "Savepoints are not supported by this database adapter",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 955,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 955,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 955,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 956,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 958,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 958,
                                        "char": 21
                                    },
                                    "name": "supportsReleaseSavePoints",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 958,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 958,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 959,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 960,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 962,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 962,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "dialect",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 963,
                                                "char": 21
                                            },
                                            "name": "releaseSavepoint",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 963,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 963,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 964,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 964,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 964,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 965,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 947,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 947,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 946,
                    "last-line": 969,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 970,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dialect",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 972,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 974,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dialect",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 974,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "dialect",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 974,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 974,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 974,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 976,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dialect",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 976,
                                            "char": 30
                                        },
                                        "name": "supportsSavePoints",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 976,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 976,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 976,
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
                                                    "type": "string",
                                                    "value": "Savepoints are not supported by this database adapter",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 979,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 979,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 979,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 980,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 982,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 982,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "dialect",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 983,
                                                "char": 21
                                            },
                                            "name": "rollbackSavepoint",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 983,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 983,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 984,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 984,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 984,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 985,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 971,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 971,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 970,
                    "last-line": 989,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 990,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 990,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 992,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 992,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 993,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 991,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 990,
                    "last-line": 997,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDialect",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "dialect",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DialectInterface",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 998,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 998,
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
                                    "property": "dialect",
                                    "expr": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1000,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1000,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1001,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dialect used to produce the SQL\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 998,
                    "last-line": 1005,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1006,
                            "char": 94
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1008,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "transactionLevel",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1008,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1008,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1008,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1008,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1008,
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
                                                    "value": "Nested transaction with savepoints behavior cannot be changed while a transaction is open",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1011,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1011,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1011,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1012,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1014,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1014,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "dialect",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1014,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1014,
                                            "char": 36
                                        },
                                        "name": "supportsSavePoints",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1014,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1014,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1014,
                                "char": 58
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
                                                    "value": "Savepoints are not supported by this database adapter",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1017,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1017,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1017,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1018,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1020,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "transactionsWithSavepoints",
                                    "expr": {
                                        "type": "variable",
                                        "value": "nestedTransactionsWithSavepoints",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1020,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1020,
                                    "char": 80
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1022,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1022,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1023,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1007,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1007,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1007,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1006,
                    "last-line": 1027,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1028,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1030,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "dialect",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1030,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1030,
                                    "char": 30
                                },
                                "name": "sharedLock",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sqlQuery",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1030,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1030,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1030,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1031,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1029,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1029,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1028,
                    "last-line": 1036,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "supportSequences",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1039,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1040,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the database system requires a sequence to produce\n     * auto-numeric values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1038,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1038,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1037,
                    "last-line": 1050,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1051,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1051,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1051,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1053,
                                            "char": 21
                                        },
                                        "name": "fetchOne",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1053,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "dialect",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1053,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1053,
                                                        "char": 45
                                                    },
                                                    "name": "tableExists",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "tableName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1053,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1053,
                                                            "char": 67
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "schemaName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1053,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1053,
                                                            "char": 79
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1053,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1053,
                                                "char": 80
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Db",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1053,
                                                        "char": 95
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "FETCH_NUM",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1053,
                                                        "char": 95
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1053,
                                                    "char": 95
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1053,
                                                "char": 95
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1053,
                                        "char": 96
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1053,
                                        "char": 98
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1053,
                                    "char": 100
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1053,
                                    "char": 103
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1053,
                                "char": 103
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1054,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL checking for the existence of a schema.table\n     *\n     *```php\n     * var_dump(\n     *     $connection->tableExists(\"blog\", \"posts\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1052,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1052,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1051,
                    "last-line": 1064,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1065,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1065,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1065,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1067,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1069,
                            "char": 11
                        },
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
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1069,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "dialect",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1069,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1069,
                                            "char": 33
                                        },
                                        "name": "tableOptions",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tableName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1069,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1069,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1069,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1069,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1069,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1069,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1071,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "sql",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1071,
                                    "char": 17
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1071,
                                "char": 17
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1072,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1073,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1075,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1075,
                                        "char": 21
                                    },
                                    "name": "fetchAll",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "sql",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1075,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1075,
                                            "char": 34
                                        },
                                        {
                                            "parameter": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "Db",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1075,
                                                    "char": 51
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "FETCH_ASSOC",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1075,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1075,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1075,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1075,
                                    "char": 52
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1075,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1075,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1076,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets creation options from a table\n     *\n     *```php\n     * print_r(\n     *     $connection->tableOptions(\"robots\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1066,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1066,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1065,
                    "last-line": 1111,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1112,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1112,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1112,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "whereCondition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1112,
                                "char": 91
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1112,
                            "char": 91
                        },
                        {
                            "type": "parameter",
                            "name": "dataTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1112,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1112,
                            "char": 113
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "placeholders",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1114,
                                    "char": 25
                                },
                                {
                                    "variable": "updateValues",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1114,
                                    "char": 39
                                },
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1114,
                                    "char": 49
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1114,
                                    "char": 56
                                },
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1114,
                                    "char": 63
                                },
                                {
                                    "variable": "bindDataTypes",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1114,
                                    "char": 78
                                },
                                {
                                    "variable": "escapedField",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1115,
                                    "char": 25
                                },
                                {
                                    "variable": "bindType",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1115,
                                    "char": 35
                                },
                                {
                                    "variable": "escapedTable",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1115,
                                    "char": 49
                                },
                                {
                                    "variable": "setClause",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1115,
                                    "char": 60
                                },
                                {
                                    "variable": "updateSql",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1115,
                                    "char": 71
                                },
                                {
                                    "variable": "conditions",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1116,
                                    "char": 23
                                },
                                {
                                    "variable": "whereBind",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1116,
                                    "char": 34
                                },
                                {
                                    "variable": "whereTypes",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1116,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1118,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "placeholders",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1118,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1118,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "updateValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1119,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1119,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1121,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "bindDataTypes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1121,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1121,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1127,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "values",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1127,
                                "char": 39
                            },
                            "key": "position",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
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
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1128,
                                                    "char": 56
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "fields",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1128,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "position",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1128,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1128,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1128,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1128,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1128,
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
                                                            "value": "The number of values in the update is not the same as fields",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1131,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1131,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1131,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1132,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1134,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escapedField",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1134,
                                                    "char": 37
                                                },
                                                "name": "escapeIdentifier",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1134,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1134,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1134,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1134,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1136,
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
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1136,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1136,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1136,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1136,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1136,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "RawValue",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1136,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1136,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1136,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "placeholders",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "escapedField",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1137,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": " = ",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1137,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1137,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "cast",
                                                            "left": "string",
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1137,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1137,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1137,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1137,
                                                    "char": 73
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1138,
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
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1139,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1139,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1139,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1139,
                                                "char": 43
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "value",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "string",
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1140,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1140,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1140,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1141,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1143,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1143,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1143,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1143,
                                                "char": 35
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "placeholders",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "escapedField",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1144,
                                                                    "char": 55
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": " = null",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1144,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1144,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1144,
                                                            "char": 64
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1145,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "updateValues",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1146,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1146,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1148,
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
                                                                "value": "dataTypes",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1148,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1148,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1148,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1148,
                                                        "char": 50
                                                    },
                                                    "statements": [
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
                                                                            "value": "bindType",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 1149,
                                                                            "char": 74
                                                                        },
                                                                        "right": {
                                                                            "type": "array-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "dataTypes",
                                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                "line": 1149,
                                                                                "char": 63
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "position",
                                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                "line": 1149,
                                                                                "char": 72
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                            "line": 1149,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 1149,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1149,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1149,
                                                                "char": 74
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
                                                                                    "value": "Incomplete number of bind types",
                                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                    "line": 1152,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                                "line": 1152,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 1152,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1153,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1155,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable-append",
                                                                    "operator": "assign",
                                                                    "variable": "bindDataTypes",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "bindType",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                        "line": 1155,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1155,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1156,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1158,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "placeholders",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "escapedField",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1158,
                                                                    "char": 55
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": " = ?",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1158,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1158,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1158,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1159,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1160,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1161,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1163,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escapedTable",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1163,
                                            "char": 33
                                        },
                                        "name": "escapeIdentifier",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1163,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1163,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1163,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1163,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1165,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "setClause",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "join",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ", ",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1165,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1165,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "placeholders",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1165,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1165,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1165,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1165,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1167,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "whereCondition",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1167,
                                    "char": 29
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1167,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1167,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "updateSql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "UPDATE ",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1168,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "escapedTable",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1168,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1168,
                                                            "char": 52
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": " SET ",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1168,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1168,
                                                        "char": 60
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "setClause",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1168,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1168,
                                                    "char": 72
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " WHERE ",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1168,
                                                    "char": 81
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1168,
                                                "char": 81
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1168,
                                            "char": 81
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1173,
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
                                                "value": "whereCondition",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1173,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1173,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1173,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1173,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "updateSql",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "whereCondition",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1174,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1174,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1175,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
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
                                                            "value": "whereCondition",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1180,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1180,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1180,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1180,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1180,
                                                "char": 60
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
                                                                    "value": "Invalid WHERE clause conditions",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1181,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1181,
                                                                "char": 72
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1181,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1182,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1188,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1188,
                                                    "char": 65
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "whereCondition",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1188,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "conditions",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1188,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1188,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1188,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "updateSql",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "conditions",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1189,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1189,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1190,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1196,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "whereBind",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1196,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "whereCondition",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1196,
                                                        "char": 51
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "bind",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1196,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1196,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1196,
                                                "char": 58
                                            },
                                            "statements": [
                                                {
                                                    "type": "fcall",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "merge_append",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "updateValues",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1197,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1197,
                                                                "char": 46
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "whereBind",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1197,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1197,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1197,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1198,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1204,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "whereTypes",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1204,
                                                    "char": 64
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "whereCondition",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1204,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "bindTypes",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1204,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1204,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1204,
                                                "char": 64
                                            },
                                            "statements": [
                                                {
                                                    "type": "fcall",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "merge_append",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindDataTypes",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1205,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1205,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "whereTypes",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                    "line": 1205,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1205,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1205,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1206,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1207,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1208,
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
                                            "variable": "updateSql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "UPDATE ",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1209,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "escapedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1209,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1209,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " SET ",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1209,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1209,
                                                    "char": 60
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "setClause",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1209,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1209,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1209,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1210,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1215,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "bindDataTypes",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1215,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1215,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1215,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1215,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1216,
                                            "char": 25
                                        },
                                        "name": "execute",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "updateSql",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1216,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1216,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "updateValues",
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1216,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1216,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1216,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1217,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1219,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1219,
                                    "char": 21
                                },
                                "name": "execute",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "updateSql",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1219,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1219,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "updateValues",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1219,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1219,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "bindDataTypes",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1219,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1219,
                                        "char": 70
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1219,
                                "char": 71
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1220,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Updates data on a table using custom RBDM SQL syntax\n     *\n     * ```php\n     * \/\/ Updating existing robot\n     * $success = $connection->update(\n     *     \"robots\",\n     *     [\"name\"],\n     *     [\"New Astro Boy\"],\n     *     \"id = 101\"\n     * );\n     *\n     * \/\/ Next SQL sentence is sent to the database system\n     * UPDATE `robots` SET `name` = \"Astro boy\" WHERE id = 101\n     *\n     * \/\/ Updating existing robot with array condition and $dataTypes\n     * $success = $connection->update(\n     *     \"robots\",\n     *     [\"name\"],\n     *     [\"New Astro Boy\"],\n     *     [\n     *         \"conditions\" => \"id = ?\",\n     *         \"bind\"       => [$some_unsafe_id],\n     *         \"bindTypes\"  => [PDO::PARAM_INT], \/\/ use only if you use $dataTypes param\n     *     ],\n     *     [\n     *         PDO::PARAM_STR\n     *     ]\n     * );\n     *\n     * ```\n     *\n     * Warning! If $whereCondition is string it not escaped.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1113,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1113,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1112,
                    "last-line": 1239,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1240,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1240,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1240,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1240,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1240,
                                "char": 105
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1240,
                            "char": 105
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "values",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1242,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1242,
                                    "char": 24
                                },
                                {
                                    "variable": "fields",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1242,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1242,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1243,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1243,
                                    "char": 18
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1243,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1245,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1245,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1245,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1245,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1245,
                                    "char": 34
                                },
                                "right": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1245,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1245,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1245,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1246,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1247,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1249,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1249,
                                "char": 34
                            },
                            "key": "field",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "fields",
                                            "expr": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1250,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1250,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1251,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "values",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1251,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1251,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1252,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1254,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1254,
                                    "char": 21
                                },
                                "name": "update",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "table",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1254,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1254,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fields",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1254,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1254,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "values",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1254,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1254,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "whereCondition",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1254,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1254,
                                        "char": 66
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "dataTypes",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1254,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1254,
                                        "char": 77
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1254,
                                "char": 78
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1255,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1241,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1241,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1240,
                    "last-line": 1260,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useExplicitIdValue",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1263,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1264,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the database system requires an explicit value for identity\n     * columns\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1262,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1262,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1261,
                    "last-line": 1274,
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
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1275,
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
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1275,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1275,
                            "char": 75
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                            "line": 1277,
                                            "char": 21
                                        },
                                        "name": "fetchOne",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1277,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "dialect",
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1277,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1277,
                                                        "char": 45
                                                    },
                                                    "name": "viewExists",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "viewName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1277,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1277,
                                                            "char": 65
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "schemaName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                                "line": 1277,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                            "line": 1277,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1277,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1277,
                                                "char": 78
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Db",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1277,
                                                        "char": 93
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "FETCH_NUM",
                                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                        "line": 1277,
                                                        "char": 93
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                    "line": 1277,
                                                    "char": 93
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                                "line": 1277,
                                                "char": 93
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1277,
                                        "char": 94
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                        "line": 1277,
                                        "char": 96
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1277,
                                    "char": 98
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                    "line": 1277,
                                    "char": 101
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1277,
                                "char": 101
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter.zep",
                            "line": 1278,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL checking for the existence of a schema.view\n     *\n     *```php\n     * var_dump(\n     *     $connection->viewExists(\"active_users\", \"posts\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter.zep",
                                "line": 1276,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter.zep",
                        "line": 1276,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter.zep",
                    "line": 1275,
                    "last-line": 1279,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/Adapter.zep",
            "line": 21,
            "char": 14
        },
        "file": "\/app\/phalcon\/Db\/Adapter.zep",
        "line": 21,
        "char": 14
    }
]