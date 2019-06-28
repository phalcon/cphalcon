[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db\\Dialect",
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Dialect",
                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Column",
                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                "line": 14,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Exception",
                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                "line": 15,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\IndexInterface",
                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                "line": 16,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ColumnInterface",
                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                "line": 17,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ReferenceInterface",
                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                "line": 18,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\DialectInterface",
                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                "line": 19,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Generates database specific SQL for the MySQL RDBMS\n *",
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "Mysql",
        "abstract": 0,
        "final": 0,
        "extends": "Dialect",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "escapeChar",
                    "default": {
                        "type": "string",
                        "value": "`",
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 29,
                        "char": 29
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 33,
                    "char": 6
                }
            ],
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 34,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 34,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 34,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 34,
                            "char": 94
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "afterPosition",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 36,
                                    "char": 26
                                },
                                {
                                    "variable": "defaultValue",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 36,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 37,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 37,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 39,
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
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "ALTER TABLE ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 39,
                                                            "char": 32
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 39,
                                                                "char": 39
                                                            },
                                                            "name": "prepareTable",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "tableName",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 39,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 39,
                                                                    "char": 62
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "schemaName",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 39,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 39,
                                                                    "char": 74
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 39,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 39,
                                                        "char": 76
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " ADD `",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 39,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 39,
                                                    "char": 85
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 39,
                                                        "char": 94
                                                    },
                                                    "name": "getName",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 39,
                                                    "char": 105
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 39,
                                                "char": 105
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "` ",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 39,
                                                "char": 110
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 39,
                                            "char": 110
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 39,
                                                "char": 117
                                            },
                                            "name": "getColumnDefinition",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 39,
                                                        "char": 144
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 39,
                                                    "char": 144
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 39,
                                            "char": 145
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 39,
                                        "char": 145
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 39,
                                    "char": 145
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 41,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 41,
                                    "char": 19
                                },
                                "name": "hasDefault",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 41,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "defaultValue",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 42,
                                                    "char": 39
                                                },
                                                "name": "getDefault",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 42,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 42,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 44,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "memstr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "strtoupper",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "defaultValue",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 44,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 44,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 44,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 44,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "CURRENT_TIMESTAMP",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 44,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 44,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 44,
                                        "char": 68
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
                                                        "type": "string",
                                                        "value": " DEFAULT CURRENT_TIMESTAMP",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 45,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 45,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 46,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": " DEFAULT \\\"",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 47,
                                                                "char": 39
                                                            },
                                                            "right": {
                                                                "type": "fcall",
                                                                "name": "addcslashes",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "defaultValue",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 47,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 47,
                                                                        "char": 65
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "\\\"",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 47,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 47,
                                                                        "char": 69
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 47,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 47,
                                                            "char": 71
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "\\\"",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 47,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 47,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 47,
                                                    "char": 75
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 48,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 49,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 51,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 51,
                                    "char": 19
                                },
                                "name": "isNotNull",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 51,
                                "char": 32
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
                                                "type": "string",
                                                "value": " NOT NULL",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 52,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 52,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 53,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 55,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 55,
                                    "char": 19
                                },
                                "name": "isAutoIncrement",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 55,
                                "char": 38
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
                                                "type": "string",
                                                "value": " AUTO_INCREMENT",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 56,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 56,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 57,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 59,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 59,
                                    "char": 19
                                },
                                "name": "isFirst",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 59,
                                "char": 30
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
                                                "type": "string",
                                                "value": " FIRST",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 60,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 60,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 61,
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
                                            "variable": "afterPosition",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 62,
                                                    "char": 40
                                                },
                                                "name": "getAfterPosition",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 62,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 62,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 64,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "afterPosition",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 64,
                                        "char": 30
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": " AFTER `",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 65,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "afterPosition",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 65,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 65,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "`",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 65,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 65,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 65,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 66,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 67,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 69,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 69,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 70,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 35,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 35,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 34,
                    "last-line": 74,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 75,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 75,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 75,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 75,
                            "char": 104
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "onDelete",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 77,
                                    "char": 21
                                },
                                {
                                    "variable": "onUpdate",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 77,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 78,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 78,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 80,
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
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "ALTER TABLE ",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 80,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 80,
                                                    "char": 39
                                                },
                                                "name": "prepareTable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tableName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 80,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 80,
                                                        "char": 62
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "schemaName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 80,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 80,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 80,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 80,
                                            "char": 76
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": " ADD",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 80,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 80,
                                        "char": 82
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 80,
                                    "char": 82
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 81,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "reference",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 81,
                                    "char": 22
                                },
                                "name": "getName",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 81,
                                "char": 33
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": " CONSTRAINT `",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 82,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "reference",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 82,
                                                            "char": 49
                                                        },
                                                        "name": "getName",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 82,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 82,
                                                    "char": 60
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "`",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 82,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 82,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 82,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 83,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 85,
                            "char": 11
                        },
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
                                                                "value": " FOREIGN KEY (",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 85,
                                                                "char": 34
                                                            },
                                                            "right": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 85,
                                                                    "char": 41
                                                                },
                                                                "name": "getColumnList",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "reference",
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 85,
                                                                                "char": 66
                                                                            },
                                                                            "name": "getColumns",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 85,
                                                                            "char": 79
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 85,
                                                                        "char": 79
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 85,
                                                                "char": 81
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 85,
                                                            "char": 81
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ") REFERENCES ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 85,
                                                            "char": 97
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 85,
                                                        "char": 97
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 85,
                                                            "char": 104
                                                        },
                                                        "name": "prepareTable",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "reference",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 85,
                                                                        "char": 128
                                                                    },
                                                                    "name": "getReferencedTable",
                                                                    "call-type": 1,
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 85,
                                                                    "char": 149
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 85,
                                                                "char": 149
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "reference",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 85,
                                                                        "char": 161
                                                                    },
                                                                    "name": "getReferencedSchema",
                                                                    "call-type": 1,
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 85,
                                                                    "char": 183
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 85,
                                                                "char": 183
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 85,
                                                        "char": 185
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 85,
                                                    "char": 185
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "(",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 85,
                                                    "char": 189
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 85,
                                                "char": 189
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 85,
                                                    "char": 196
                                                },
                                                "name": "getColumnList",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "reference",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 85,
                                                                "char": 221
                                                            },
                                                            "name": "getReferencedColumns",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 85,
                                                            "char": 244
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 85,
                                                        "char": 244
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 85,
                                                "char": 246
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 85,
                                            "char": 246
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 85,
                                            "char": 249
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 85,
                                        "char": 249
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 85,
                                    "char": 249
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 87,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "onDelete",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reference",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 87,
                                            "char": 34
                                        },
                                        "name": "getOnDelete",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 87,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 87,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 88,
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
                                        "value": "onDelete",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 88,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 88,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 88,
                                "char": 28
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
                                                    "value": " ON DELETE ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 89,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "onDelete",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 89,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 89,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 89,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 92,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "onUpdate",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reference",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 92,
                                            "char": 34
                                        },
                                        "name": "getOnUpdate",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 92,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 92,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 93,
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
                                        "value": "onUpdate",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 93,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 93,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 93,
                                "char": 28
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
                                                    "value": " ON UPDATE ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 94,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "onUpdate",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 94,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 94,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 94,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 95,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 97,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 97,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 98,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 76,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 76,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 75,
                    "last-line": 102,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 103,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 103,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 103,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 103,
                            "char": 91
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "indexType",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 105,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 106,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 106,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 108,
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
                                            "value": "ALTER TABLE ",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 108,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 108,
                                                "char": 39
                                            },
                                            "name": "prepareTable",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 108,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 108,
                                                    "char": 62
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 108,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 108,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 108,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 108,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 108,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 110,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "indexType",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 110,
                                            "char": 31
                                        },
                                        "name": "getType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 110,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 110,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 112,
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
                                        "value": "indexType",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 112,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 112,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 112,
                                "char": 29
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": " ADD ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 113,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "indexType",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 113,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 113,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " INDEX ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 113,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 113,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 113,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "string",
                                                "value": " ADD INDEX ",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 115,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 115,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 116,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 118,
                            "char": 11
                        },
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
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "`",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 118,
                                                        "char": 21
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "index",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 118,
                                                            "char": 29
                                                        },
                                                        "name": "getName",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 118,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 118,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "` (",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 118,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 118,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 118,
                                                    "char": 53
                                                },
                                                "name": "getColumnList",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "index",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 118,
                                                                "char": 74
                                                            },
                                                            "name": "getColumns",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 118,
                                                            "char": 87
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 118,
                                                        "char": 87
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 118,
                                                "char": 89
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 118,
                                            "char": 89
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 118,
                                            "char": 92
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 118,
                                        "char": 92
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 118,
                                    "char": 92
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 120,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 120,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 121,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 104,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 104,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 103,
                    "last-line": 125,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 126,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 126,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 126,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 126,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
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
                                                "value": "ALTER TABLE ",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 128,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 128,
                                                    "char": 36
                                                },
                                                "name": "prepareTable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tableName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 128,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 128,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "schemaName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 128,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 128,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 128,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 128,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": " ADD PRIMARY KEY (",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 128,
                                            "char": 94
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 128,
                                        "char": 94
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 128,
                                            "char": 101
                                        },
                                        "name": "getColumnList",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "index",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 128,
                                                        "char": 122
                                                    },
                                                    "name": "getColumns",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 128,
                                                    "char": 135
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 128,
                                                "char": 135
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 128,
                                        "char": 137
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 128,
                                    "char": 137
                                },
                                "right": {
                                    "type": "string",
                                    "value": ")",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 128,
                                    "char": 140
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 128,
                                "char": 140
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 129,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 127,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 127,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 126,
                    "last-line": 133,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 134,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 134,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 134,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "temporary",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 136,
                                    "char": 22
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 136,
                                    "char": 31
                                },
                                {
                                    "variable": "table",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 136,
                                    "char": 38
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 136,
                                    "char": 47
                                },
                                {
                                    "variable": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 136,
                                    "char": 55
                                },
                                {
                                    "variable": "indexes",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 136,
                                    "char": 64
                                },
                                {
                                    "variable": "index",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 136,
                                    "char": 71
                                },
                                {
                                    "variable": "reference",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 137,
                                    "char": 22
                                },
                                {
                                    "variable": "references",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 137,
                                    "char": 34
                                },
                                {
                                    "variable": "indexName",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 137,
                                    "char": 45
                                },
                                {
                                    "variable": "columnLine",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 137,
                                    "char": 57
                                },
                                {
                                    "variable": "indexType",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 137,
                                    "char": 68
                                },
                                {
                                    "variable": "onDelete",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 137,
                                    "char": 78
                                },
                                {
                                    "variable": "onUpdate",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 138,
                                    "char": 21
                                },
                                {
                                    "variable": "defaultValue",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 138,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 139,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "createLines",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 139,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 140,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "indexSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 140,
                                    "char": 24
                                },
                                {
                                    "variable": "referenceSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 140,
                                    "char": 38
                                },
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 140,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 142,
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
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 142,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 142,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 142,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 142,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 142,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 142,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 142,
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
                                                    "value": "The index 'columns' is required in the definition array",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 145,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 145,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 145,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 146,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 148,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "table",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 148,
                                            "char": 26
                                        },
                                        "name": "prepareTable",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tableName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 148,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 148,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 148,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 148,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 148,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 148,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 150,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "temporary",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 150,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 150,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 151,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 151,
                                    "char": 47
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 151,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 151,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 151,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 151,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "fetch",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "temporary",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 152,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 152,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "temporary",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 152,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 152,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 152,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 153,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 158,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "temporary",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 158,
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
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "CREATE TEMPORARY TABLE ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 159,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 159,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 159,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " (\\n\\t",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 159,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 159,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 159,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 160,
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
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "CREATE TABLE ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 161,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 161,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 161,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " (\\n\\t",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 161,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 161,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 161,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 162,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 164,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "createLines",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 164,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 164,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 166,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "columns",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 166,
                                "char": 31
                            },
                            "value": "column",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnLine",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "`",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 167,
                                                            "char": 32
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "column",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 167,
                                                                "char": 41
                                                            },
                                                            "name": "getName",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 167,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 167,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "` ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 167,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 167,
                                                    "char": 57
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 167,
                                                        "char": 64
                                                    },
                                                    "name": "getColumnDefinition",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "column",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 167,
                                                                "char": 91
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 167,
                                                            "char": 91
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 167,
                                                    "char": 92
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 167,
                                                "char": 92
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 167,
                                            "char": 92
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 172,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 172,
                                            "char": 23
                                        },
                                        "name": "hasDefault",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 172,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "defaultValue",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 173,
                                                            "char": 43
                                                        },
                                                        "name": "getDefault",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 173,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 173,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 175,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "strtoupper",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "defaultValue",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 175,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 175,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 175,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 175,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "CURRENT_TIMESTAMP",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 175,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 175,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 175,
                                                "char": 72
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnLine",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": " DEFAULT CURRENT_TIMESTAMP",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 176,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 176,
                                                            "char": 64
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 177,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnLine",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": " DEFAULT \\\"",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 178,
                                                                        "char": 50
                                                                    },
                                                                    "right": {
                                                                        "type": "fcall",
                                                                        "name": "addcslashes",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "defaultValue",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 178,
                                                                                    "char": 76
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 178,
                                                                                "char": 76
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "\\\"",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 178,
                                                                                    "char": 80
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 178,
                                                                                "char": 80
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 178,
                                                                        "char": 82
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 178,
                                                                    "char": 82
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "\\\"",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 178,
                                                                    "char": 86
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 178,
                                                                "char": 86
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 178,
                                                            "char": 86
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 179,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 180,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 185,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 185,
                                            "char": 23
                                        },
                                        "name": "isNotNull",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 185,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnLine",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": " NOT NULL",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 186,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 186,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 187,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 192,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 192,
                                            "char": 23
                                        },
                                        "name": "isAutoIncrement",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 192,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnLine",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": " AUTO_INCREMENT",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 193,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 193,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 194,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 199,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 199,
                                            "char": 23
                                        },
                                        "name": "isPrimary",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 199,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnLine",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": " PRIMARY KEY",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 200,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 200,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 201,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 203,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "createLines",
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnLine",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 203,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 203,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 204,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 209,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "indexes",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 209,
                                    "char": 47
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 209,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "indexes",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 209,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 209,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 209,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "indexes",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 210,
                                        "char": 34
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
                                                    "variable": "indexName",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "index",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 211,
                                                            "char": 39
                                                        },
                                                        "name": "getName",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 211,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 211,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 212,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "indexType",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "index",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 212,
                                                            "char": 39
                                                        },
                                                        "name": "getType",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 212,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 212,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 217,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "indexName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 217,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "PRIMARY",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 217,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 217,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "indexSql",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "PRIMARY KEY (",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 218,
                                                                        "char": 50
                                                                    },
                                                                    "right": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 218,
                                                                            "char": 57
                                                                        },
                                                                        "name": "getColumnList",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "index",
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 218,
                                                                                        "char": 78
                                                                                    },
                                                                                    "name": "getColumns",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 218,
                                                                                    "char": 91
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 218,
                                                                                "char": 91
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 218,
                                                                        "char": 93
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 218,
                                                                    "char": 93
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": ")",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 218,
                                                                    "char": 96
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 218,
                                                                "char": 96
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 218,
                                                            "char": 96
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 219,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "empty",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "indexType",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 220,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 220,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 220,
                                                        "char": 41
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "indexSql",
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
                                                                                            "type": "variable",
                                                                                            "value": "indexType",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 221,
                                                                                            "char": 50
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "string",
                                                                                            "value": " KEY `",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 221,
                                                                                            "char": 59
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 221,
                                                                                        "char": 59
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "indexName",
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 221,
                                                                                        "char": 71
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 221,
                                                                                    "char": 71
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "` (",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 221,
                                                                                    "char": 77
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 221,
                                                                                "char": 77
                                                                            },
                                                                            "right": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 221,
                                                                                    "char": 84
                                                                                },
                                                                                "name": "getColumnList",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "mcall",
                                                                                            "variable": {
                                                                                                "type": "variable",
                                                                                                "value": "index",
                                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                "line": 221,
                                                                                                "char": 105
                                                                                            },
                                                                                            "name": "getColumns",
                                                                                            "call-type": 1,
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 221,
                                                                                            "char": 118
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 221,
                                                                                        "char": 118
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 221,
                                                                                "char": 120
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 221,
                                                                            "char": 120
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ")",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 221,
                                                                            "char": 123
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 221,
                                                                        "char": 123
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 221,
                                                                    "char": 123
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 222,
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
                                                                    "variable": "indexSql",
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
                                                                                        "value": "KEY `",
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 223,
                                                                                        "char": 46
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "indexName",
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 223,
                                                                                        "char": 58
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 223,
                                                                                    "char": 58
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "` (",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 223,
                                                                                    "char": 64
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 223,
                                                                                "char": 64
                                                                            },
                                                                            "right": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 223,
                                                                                    "char": 71
                                                                                },
                                                                                "name": "getColumnList",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "mcall",
                                                                                            "variable": {
                                                                                                "type": "variable",
                                                                                                "value": "index",
                                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                "line": 223,
                                                                                                "char": 92
                                                                                            },
                                                                                            "name": "getColumns",
                                                                                            "call-type": 1,
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 223,
                                                                                            "char": 105
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 223,
                                                                                        "char": 105
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 223,
                                                                                "char": 107
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 223,
                                                                            "char": 107
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ")",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 223,
                                                                            "char": 110
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 223,
                                                                        "char": 110
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 223,
                                                                    "char": 110
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 224,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 225,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 227,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "createLines",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "indexSql",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 227,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 227,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 228,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 229,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 234,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "references",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 234,
                                    "char": 53
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 234,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "references",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 234,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 234,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 234,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "references",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 235,
                                        "char": 41
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
                                                    "variable": "referenceSql",
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
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "string",
                                                                                            "value": "CONSTRAINT `",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 236,
                                                                                            "char": 49
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "mcall",
                                                                                            "variable": {
                                                                                                "type": "variable",
                                                                                                "value": "reference",
                                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                "line": 236,
                                                                                                "char": 61
                                                                                            },
                                                                                            "name": "getName",
                                                                                            "call-type": 1,
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 236,
                                                                                            "char": 72
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 236,
                                                                                        "char": 72
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": "` FOREIGN KEY (",
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 236,
                                                                                        "char": 90
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 236,
                                                                                    "char": 90
                                                                                },
                                                                                "right": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 236,
                                                                                        "char": 97
                                                                                    },
                                                                                    "name": "getColumnList",
                                                                                    "call-type": 1,
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "mcall",
                                                                                                "variable": {
                                                                                                    "type": "variable",
                                                                                                    "value": "reference",
                                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                    "line": 236,
                                                                                                    "char": 122
                                                                                                },
                                                                                                "name": "getColumns",
                                                                                                "call-type": 1,
                                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                "line": 236,
                                                                                                "char": 135
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 236,
                                                                                            "char": 135
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 236,
                                                                                    "char": 137
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 236,
                                                                                "char": 137
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": ")",
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 237,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 237,
                                                                            "char": 21
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": " REFERENCES `",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 237,
                                                                            "char": 37
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 237,
                                                                        "char": 37
                                                                    },
                                                                    "right": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "reference",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 237,
                                                                            "char": 49
                                                                        },
                                                                        "name": "getReferencedTable",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 237,
                                                                        "char": 71
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 237,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "`(",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 237,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 237,
                                                                "char": 76
                                                            },
                                                            "right": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 237,
                                                                    "char": 83
                                                                },
                                                                "name": "getColumnList",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "reference",
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 237,
                                                                                "char": 108
                                                                            },
                                                                            "name": "getReferencedColumns",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 237,
                                                                            "char": 131
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 237,
                                                                        "char": 131
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 237,
                                                                "char": 133
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 237,
                                                            "char": 133
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ")",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 237,
                                                            "char": 136
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 237,
                                                        "char": 136
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 237,
                                                    "char": 136
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 239,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "onDelete",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "reference",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 239,
                                                            "char": 42
                                                        },
                                                        "name": "getOnDelete",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 239,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 239,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 240,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "onDelete",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 240,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 240,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 240,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "referenceSql",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": " ON DELETE ",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 241,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "onDelete",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 241,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 241,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 241,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 242,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 244,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "onUpdate",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "reference",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 244,
                                                            "char": 42
                                                        },
                                                        "name": "getOnUpdate",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 244,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 244,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 245,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "onUpdate",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 245,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 245,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 245,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "referenceSql",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": " ON UPDATE ",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 246,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "onUpdate",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 246,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 246,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 246,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 247,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 249,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "createLines",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "referenceSql",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 249,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 249,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 250,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 251,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 253,
                            "char": 11
                        },
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
                                            "type": "fcall",
                                            "name": "join",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": ",\\n\\t",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 253,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 253,
                                                    "char": 29
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "createLines",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 253,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 253,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 253,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "\\n)",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 253,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 253,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 253,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 255,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 255,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 255,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 255,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 255,
                                "char": 38
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
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 256,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 256,
                                                        "char": 32
                                                    },
                                                    "name": "getTableOptions",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "definition",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 256,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 256,
                                                            "char": 59
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 256,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 256,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 256,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 257,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 259,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 259,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 260,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 134,
                    "last-line": 264,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 265,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 265,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 265,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 265,
                            "char": 93
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "viewSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 267,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 269,
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
                                            "value": "viewSql",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 269,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 269,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "sql",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 269,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 269,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 269,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 269,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 269,
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
                                                    "value": "The index 'sql' is required in the definition array",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 272,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 272,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 272,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 273,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 275,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "CREATE VIEW ",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 275,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 275,
                                                "char": 36
                                            },
                                            "name": "prepareTable",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "viewName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 275,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 275,
                                                    "char": 58
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 275,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 275,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 275,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 275,
                                        "char": 72
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": " AS ",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 275,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 275,
                                    "char": 79
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "viewSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 275,
                                    "char": 88
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 275,
                                "char": 88
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 276,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 266,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 266,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 265,
                    "last-line": 286,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 287,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 287,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 287,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "DESCRIBE ",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 289,
                                    "char": 26
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 289,
                                        "char": 33
                                    },
                                    "name": "prepareTable",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "table",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 289,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 289,
                                            "char": 52
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "schema",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 289,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 289,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 289,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 289,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 290,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL describing a table\n     *\n     * ```php\n     * print_r(\n     *     $dialect->describeColumns(\"posts\")\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 288,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 288,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 287,
                    "last-line": 294,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 295,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 295,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 295,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "SHOW INDEXES FROM ",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 297,
                                    "char": 35
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 297,
                                        "char": 42
                                    },
                                    "name": "prepareTable",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "table",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 297,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 297,
                                            "char": 61
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "schema",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 297,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 297,
                                            "char": 69
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 297,
                                    "char": 70
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 297,
                                "char": 70
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 298,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 296,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 296,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 295,
                    "last-line": 302,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 303,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 303,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 303,
                            "char": 75
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 305,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 307,
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
                                        "type": "string",
                                        "value": "SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, RC.DELETE_RULE FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 307,
                                        "char": 452
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 307,
                                    "char": 452
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 309,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "schema",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 309,
                                "char": 19
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "KCU.CONSTRAINT_SCHEMA = '",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 310,
                                                                "char": 49
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "schema",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 310,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 310,
                                                            "char": 58
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "' AND KCU.TABLE_NAME = '",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 310,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 310,
                                                        "char": 85
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 310,
                                                        "char": 93
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 310,
                                                    "char": 93
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "'",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 310,
                                                    "char": 96
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 310,
                                                "char": 96
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 310,
                                            "char": 96
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 311,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = '",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 312,
                                                        "char": 81
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 312,
                                                        "char": 89
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 312,
                                                    "char": 89
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "'",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 312,
                                                    "char": 92
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 312,
                                                "char": 92
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 312,
                                            "char": 92
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 313,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 315,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 315,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 316,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 304,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 304,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 303,
                    "last-line": 320,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 321,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 321,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "columnName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 321,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
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
                                                "value": "ALTER TABLE ",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 323,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 323,
                                                    "char": 36
                                                },
                                                "name": "prepareTable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tableName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 323,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 323,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "schemaName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 323,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 323,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 323,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 323,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": " DROP COLUMN `",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 323,
                                            "char": 90
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 323,
                                        "char": 90
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "columnName",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 323,
                                        "char": 103
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 323,
                                    "char": 103
                                },
                                "right": {
                                    "type": "string",
                                    "value": "`",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 323,
                                    "char": 106
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 323,
                                "char": 106
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 324,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 322,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 322,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 321,
                    "last-line": 328,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 329,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 329,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "referenceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 329,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
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
                                                "value": "ALTER TABLE ",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 331,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 331,
                                                    "char": 36
                                                },
                                                "name": "prepareTable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tableName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 331,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 331,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "schemaName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 331,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 331,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 331,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 331,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": " DROP FOREIGN KEY `",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 331,
                                            "char": 95
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 331,
                                        "char": 95
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "referenceName",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 331,
                                        "char": 111
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 331,
                                    "char": 111
                                },
                                "right": {
                                    "type": "string",
                                    "value": "`",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 331,
                                    "char": 114
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 331,
                                "char": 114
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 332,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 330,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 330,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 329,
                    "last-line": 336,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 337,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 337,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "indexName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 337,
                            "char": 87
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
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
                                                "value": "ALTER TABLE ",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 339,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 339,
                                                    "char": 36
                                                },
                                                "name": "prepareTable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tableName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 339,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 339,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "schemaName",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 339,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 339,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 339,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 339,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": " DROP INDEX `",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 339,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 339,
                                        "char": 89
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "indexName",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 339,
                                        "char": 101
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 339,
                                    "char": 101
                                },
                                "right": {
                                    "type": "string",
                                    "value": "`",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 339,
                                    "char": 104
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 339,
                                "char": 104
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 340,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to delete an index from a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 338,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 338,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 337,
                    "last-line": 344,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 345,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 345,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "ALTER TABLE ",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 347,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 347,
                                            "char": 36
                                        },
                                        "name": "prepareTable",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tableName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 347,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 347,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 347,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 347,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 347,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 347,
                                    "char": 73
                                },
                                "right": {
                                    "type": "string",
                                    "value": " DROP PRIMARY KEY",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 347,
                                    "char": 92
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 347,
                                "char": 92
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 348,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 346,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 346,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 345,
                    "last-line": 352,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 353,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 353,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 353,
                            "char": 74
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 353,
                                "char": 97
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 353,
                            "char": 97
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "table",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 355,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 357,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "table",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 357,
                                            "char": 26
                                        },
                                        "name": "prepareTable",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tableName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 357,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 357,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 357,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 357,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 357,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 357,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 359,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "ifExists",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 359,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "DROP TABLE IF EXISTS ",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 360,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "table",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 360,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 360,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 361,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 363,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "DROP TABLE ",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 363,
                                    "char": 28
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "table",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 363,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 363,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 364,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 354,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 354,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 353,
                    "last-line": 368,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 369,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 369,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 369,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 369,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 369,
                            "char": 95
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "view",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 371,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 373,
                            "char": 11
                        },
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
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 373,
                                            "char": 25
                                        },
                                        "name": "prepareTable",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "viewName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 373,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 373,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 373,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 373,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 373,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 373,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 375,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "ifExists",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 375,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "DROP VIEW IF EXISTS ",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 376,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "view",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 376,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 376,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 377,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 379,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "DROP VIEW ",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 379,
                                    "char": 27
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 379,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 379,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 380,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 370,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 370,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 369,
                    "last-line": 384,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 385,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 385,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columnType",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 387,
                                    "char": 23
                                },
                                {
                                    "variable": "columnSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 387,
                                    "char": 34
                                },
                                {
                                    "variable": "typeValues",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 387,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 389,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columnSql",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 389,
                                            "char": 31
                                        },
                                        "name": "checkColumnTypeSql",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 389,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 389,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 389,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 389,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 390,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columnType",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 390,
                                            "char": 31
                                        },
                                        "name": "checkColumnType",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 390,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 390,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 390,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 390,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 392,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "columnType",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 392,
                                "char": 27
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 394,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_BIGINTEGER",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 394,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 394,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 395,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 395,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "BIGINT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 396,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 396,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 397,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 399,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 399,
                                                                "char": 38
                                                            },
                                                            "name": "getColumnSize",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 399,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 399,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 399,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 399,
                                                                "char": 68
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 399,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 399,
                                                                    "char": 95
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 399,
                                                            "char": 96
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 399,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 399,
                                                    "char": 96
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 401,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 403,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 403,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 403,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_BIT",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 403,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 403,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 404,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 404,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "BIT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 405,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 405,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 406,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 408,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 408,
                                                            "char": 38
                                                        },
                                                        "name": "getColumnSize",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "column",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 408,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 408,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 408,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 408,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 410,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 412,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 412,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 412,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_BLOB",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 412,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 412,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 413,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 413,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "BLOB",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 414,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 414,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 415,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 417,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 419,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 419,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 419,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_BOOLEAN",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 419,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 419,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 420,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 420,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "TINYINT(1)",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 421,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 421,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 422,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 424,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 426,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 426,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 426,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_CHAR",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 426,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 426,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 427,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 427,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "CHAR",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 428,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 428,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 429,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 431,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 431,
                                                            "char": 38
                                                        },
                                                        "name": "getColumnSize",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "column",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 431,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 431,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 431,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 431,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 433,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 435,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 435,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 435,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_DATE",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 435,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 435,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 436,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 436,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "DATE",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 437,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 437,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 438,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 440,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 442,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 442,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 442,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_DATETIME",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 442,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 442,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 443,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 443,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "DATETIME",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 444,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 444,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 445,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 447,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 449,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 449,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 449,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_DECIMAL",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 449,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 449,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 450,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 450,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "DECIMAL",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 451,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 451,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 452,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 454,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 454,
                                                                "char": 38
                                                            },
                                                            "name": "getColumnSizeAndScale",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 454,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 454,
                                                                    "char": 67
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 454,
                                                            "char": 69
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 454,
                                                                "char": 76
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 454,
                                                                        "char": 103
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 454,
                                                                    "char": 103
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 454,
                                                            "char": 104
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 454,
                                                        "char": 104
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 454,
                                                    "char": 104
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 456,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 458,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 458,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 458,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_DOUBLE",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 458,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 458,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 459,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 459,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "DOUBLE",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 460,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 460,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 461,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 463,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 463,
                                                                "char": 38
                                                            },
                                                            "name": "checkColumnSizeAndScale",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 463,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 463,
                                                                    "char": 69
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 463,
                                                            "char": 71
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 463,
                                                                "char": 78
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 463,
                                                                        "char": 105
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 463,
                                                                    "char": 105
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 463,
                                                            "char": 106
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 463,
                                                        "char": 106
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 463,
                                                    "char": 106
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 465,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 467,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 467,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 467,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_ENUM",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 467,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 467,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 468,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 468,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "ENUM",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 469,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 469,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 470,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 472,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 472,
                                                            "char": 38
                                                        },
                                                        "name": "getColumnSize",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "column",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 472,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 472,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 472,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 472,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 474,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 476,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 476,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 476,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_FLOAT",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 476,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 476,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 477,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 477,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "FLOAT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 478,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 478,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 479,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 481,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 481,
                                                                "char": 38
                                                            },
                                                            "name": "checkColumnSizeAndScale",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 481,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 481,
                                                                    "char": 69
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 481,
                                                            "char": 71
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 481,
                                                                "char": 78
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 481,
                                                                        "char": 105
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 481,
                                                                    "char": 105
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 481,
                                                            "char": 106
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 481,
                                                        "char": 106
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 481,
                                                    "char": 106
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 483,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 485,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 485,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 485,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_INTEGER",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 485,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 485,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 486,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 486,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "INT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 487,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 487,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 488,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 490,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 490,
                                                                "char": 38
                                                            },
                                                            "name": "getColumnSize",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 490,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 490,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 490,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 490,
                                                                "char": 68
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 490,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 490,
                                                                    "char": 95
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 490,
                                                            "char": 96
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 490,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 490,
                                                    "char": 96
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 492,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 494,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 494,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 494,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_JSON",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 494,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 494,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 495,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 495,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "JSON",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 496,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 496,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 497,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 499,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 501,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 501,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 501,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_LONGBLOB",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 501,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 501,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 502,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 502,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "LONGBLOB",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 503,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 503,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 504,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 506,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 508,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 508,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 508,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_LONGTEXT",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 508,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 508,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 509,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 509,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "LONGTEXT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 510,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 510,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 511,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 513,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 515,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 515,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 515,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_MEDIUMBLOB",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 515,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 515,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 516,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 516,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "MEDIUMBLOB",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 517,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 517,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 518,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 520,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 522,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 522,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 522,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_MEDIUMINTEGER",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 522,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 522,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 523,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 523,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "MEDIUMINT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 524,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 524,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 525,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 527,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 527,
                                                                "char": 38
                                                            },
                                                            "name": "getColumnSize",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 527,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 527,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 527,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 527,
                                                                "char": 68
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 527,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 527,
                                                                    "char": 95
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 527,
                                                            "char": 96
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 527,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 527,
                                                    "char": 96
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 529,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 531,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 531,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 531,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_MEDIUMTEXT",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 531,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 531,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 532,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 532,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "MEDIUMTEXT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 533,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 533,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 534,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 536,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 538,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 538,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 538,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_SMALLINTEGER",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 538,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 538,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 539,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 539,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "SMALLINT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 540,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 540,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 541,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 543,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 543,
                                                                "char": 38
                                                            },
                                                            "name": "getColumnSize",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 543,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 543,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 543,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 543,
                                                                "char": 68
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 543,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 543,
                                                                    "char": 95
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 543,
                                                            "char": 96
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 543,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 543,
                                                    "char": 96
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 545,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 547,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 547,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 547,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_TEXT",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 547,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 547,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 548,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 548,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "TEXT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 549,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 549,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 550,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 552,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 554,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 554,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 554,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_TIME",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 554,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 554,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 555,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 555,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "TIME",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 556,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 556,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 557,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 559,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 561,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 561,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 561,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_TIMESTAMP",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 561,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 561,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 562,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 562,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "TIMESTAMP",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 563,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 563,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 564,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 566,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 568,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 568,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 568,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_TINYBLOB",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 568,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 568,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 569,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 569,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "TINYBLOB",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 570,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 570,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 571,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 573,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 575,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 575,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 575,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_TINYINTEGER",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 575,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 575,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 576,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 576,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "TINYINT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 577,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 577,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 578,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 580,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 580,
                                                                "char": 38
                                                            },
                                                            "name": "getColumnSize",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 580,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 580,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 580,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 580,
                                                                "char": 68
                                                            },
                                                            "name": "checkColumnUnsigned",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "column",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 580,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 580,
                                                                    "char": 95
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 580,
                                                            "char": 96
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 580,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 580,
                                                    "char": 96
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 582,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 584,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 584,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 584,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_TINYTEXT",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 584,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 584,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 585,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 585,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "TINYTEXT",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 586,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 586,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 587,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 589,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 591,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 591,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 591,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "TYPE_VARCHAR",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 591,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 591,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnSql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 592,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 592,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "columnSql",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "VARCHAR",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 593,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 593,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 594,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 596,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 596,
                                                            "char": 38
                                                        },
                                                        "name": "getColumnSize",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "column",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 596,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 596,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 596,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 596,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 598,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 600,
                                            "char": 19
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 600,
                                    "char": 19
                                },
                                {
                                    "type": "default",
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "columnSql",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 601,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 601,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 601,
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
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "Unrecognized MySQL data type at column ",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 603,
                                                                        "char": 65
                                                                    },
                                                                    "right": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "column",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 603,
                                                                            "char": 74
                                                                        },
                                                                        "name": "getName",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 604,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 604,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 604,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 604,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 605,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 607,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "typeValues",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 607,
                                                            "char": 41
                                                        },
                                                        "name": "getTypeValues",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 607,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 607,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 608,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "typeValues",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 608,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 608,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 608,
                                                "char": 38
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
                                                                "value": "typeValues",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 609,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 609,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 609,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 609,
                                                        "char": 51
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "declare",
                                                            "data-type": "variable",
                                                            "variables": [
                                                                {
                                                                    "variable": "value",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 610,
                                                                    "char": 34
                                                                },
                                                                {
                                                                    "variable": "valueSql",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 610,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 612,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "valueSql",
                                                                    "expr": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 612,
                                                                        "char": 40
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 612,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 614,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "for",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "typeValues",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 614,
                                                                "char": 49
                                                            },
                                                            "value": "value",
                                                            "reverse": 0,
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "concat-assign",
                                                                            "variable": "valueSql",
                                                                            "expr": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "string",
                                                                                        "value": "\\\"",
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 615,
                                                                                        "char": 47
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "fcall",
                                                                                        "name": "addcslashes",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "variable",
                                                                                                    "value": "value",
                                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                    "line": 615,
                                                                                                    "char": 66
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                "line": 615,
                                                                                                "char": 66
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": "\\\"",
                                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                    "line": 615,
                                                                                                    "char": 70
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                                "line": 615,
                                                                                                "char": 70
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 615,
                                                                                        "char": 72
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 615,
                                                                                    "char": 72
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "\\\", ",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                    "line": 615,
                                                                                    "char": 78
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 615,
                                                                                "char": 78
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 615,
                                                                            "char": 78
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 616,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 618,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "columnSql",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "(",
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 618,
                                                                                "char": 43
                                                                            },
                                                                            "right": {
                                                                                "type": "fcall",
                                                                                "name": "substr",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "valueSql",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 618,
                                                                                            "char": 60
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 618,
                                                                                        "char": 60
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "int",
                                                                                            "value": "0",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 618,
                                                                                            "char": 63
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 618,
                                                                                        "char": 63
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "int",
                                                                                            "value": "-2",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 618,
                                                                                            "char": 67
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 618,
                                                                                        "char": 67
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 618,
                                                                                "char": 69
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 618,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ")",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 618,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 618,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 618,
                                                                    "char": 72
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 619,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "columnSql",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "(\\\"",
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 620,
                                                                                "char": 45
                                                                            },
                                                                            "right": {
                                                                                "type": "fcall",
                                                                                "name": "addcslashes",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "typeValues",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 620,
                                                                                            "char": 69
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 620,
                                                                                        "char": 69
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "\\\"",
                                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                            "line": 620,
                                                                                            "char": 73
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                        "line": 620,
                                                                                        "char": 73
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                                "line": 620,
                                                                                "char": 75
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 620,
                                                                            "char": 75
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "\\\")",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 620,
                                                                            "char": 80
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 620,
                                                                        "char": 80
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 620,
                                                                    "char": 80
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 621,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 622,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 623,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 623,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 625,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "columnSql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 625,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 626,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the column name in MySQL\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 386,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 386,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 385,
                    "last-line": 630,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getForeignKeyChecks",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "SELECT @@foreign_key_checks",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 633,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 634,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to check DB parameter FOREIGN_KEY_CHECKS.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 632,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 632,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 631,
                    "last-line": 644,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 645,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 645,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "schemaName",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 647,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "SHOW TABLES FROM `",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 648,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "schemaName",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 648,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 648,
                                            "char": 52
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "`",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 648,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 648,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 649,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 651,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "SHOW TABLES",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 651,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 652,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * List all tables in database\n     *\n     * ```php\n     * print_r(\n     *     $dialect->listTables(\"blog\")\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 646,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 646,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 645,
                    "last-line": 656,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 657,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 657,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "schemaName",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 659,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 660,
                                                "char": 112
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "schemaName",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 660,
                                                "char": 125
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 660,
                                            "char": 125
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "' ORDER BY view_name",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 660,
                                            "char": 147
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 660,
                                        "char": 147
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 661,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 663,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 663,
                                "char": 135
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 664,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates the SQL to list all views of a schema or user\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 658,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 658,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 657,
                    "last-line": 668,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 669,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 669,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 669,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 669,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 669,
                                "char": 129
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 669,
                                "char": 137
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 669,
                            "char": 137
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "afterPosition",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 671,
                                    "char": 26
                                },
                                {
                                    "variable": "defaultValue",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 671,
                                    "char": 40
                                },
                                {
                                    "variable": "columnDefinition",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 671,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 672,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 672,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 674,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columnDefinition",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 674,
                                            "char": 37
                                        },
                                        "name": "getColumnDefinition",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 674,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 674,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 674,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 674,
                                    "char": 65
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sql",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "ALTER TABLE ",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 675,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 675,
                                                "char": 39
                                            },
                                            "name": "prepareTable",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 675,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 675,
                                                    "char": 62
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schemaName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 675,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 675,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 675,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 675,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 675,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 677,
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
                                        "value": "currentColumn",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 677,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 677,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 677,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 677,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "currentColumn",
                                            "expr": {
                                                "type": "variable",
                                                "value": "column",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 678,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 678,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 679,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 681,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "column",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 681,
                                        "char": 19
                                    },
                                    "name": "getName",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 681,
                                    "char": 32
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "currentColumn",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 681,
                                        "char": 48
                                    },
                                    "name": "getName",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 681,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 681,
                                "char": 59
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": " CHANGE COLUMN `",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 682,
                                                                    "char": 40
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "currentColumn",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 682,
                                                                        "char": 56
                                                                    },
                                                                    "name": "getName",
                                                                    "call-type": 1,
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 682,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 682,
                                                                "char": 67
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "` `",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 682,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 682,
                                                            "char": 73
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "column",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 682,
                                                                "char": 82
                                                            },
                                                            "name": "getName",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 682,
                                                            "char": 93
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 682,
                                                        "char": 93
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "` ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 682,
                                                        "char": 98
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 682,
                                                    "char": 98
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "columnDefinition",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 682,
                                                    "char": 116
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 682,
                                                "char": 116
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 682,
                                            "char": 116
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 683,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": " MODIFY `",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 684,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "column",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 684,
                                                                "char": 42
                                                            },
                                                            "name": "getName",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 684,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 684,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "` ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 684,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 684,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "columnDefinition",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 684,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 684,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 684,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 685,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 687,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 687,
                                    "char": 19
                                },
                                "name": "hasDefault",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 687,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "defaultValue",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 688,
                                                    "char": 39
                                                },
                                                "name": "getDefault",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 688,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 688,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 690,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "memstr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "strtoupper",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "defaultValue",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 690,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 690,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 690,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 690,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "CURRENT_TIMESTAMP",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 690,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 690,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 690,
                                        "char": 68
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
                                                        "type": "string",
                                                        "value": " DEFAULT CURRENT_TIMESTAMP",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 691,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 691,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 692,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": " DEFAULT \\\"",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 693,
                                                                "char": 39
                                                            },
                                                            "right": {
                                                                "type": "fcall",
                                                                "name": "addcslashes",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "defaultValue",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 693,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 693,
                                                                        "char": 65
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "\\\"",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                            "line": 693,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                        "line": 693,
                                                                        "char": 69
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 693,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 693,
                                                            "char": 71
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "\\\"",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 693,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 693,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 693,
                                                    "char": 75
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 694,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 695,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 697,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 697,
                                    "char": 19
                                },
                                "name": "isNotNull",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 697,
                                "char": 32
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
                                                "type": "string",
                                                "value": " NOT NULL",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 698,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 698,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 699,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 701,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 701,
                                    "char": 19
                                },
                                "name": "isAutoIncrement",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 701,
                                "char": 38
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
                                                "type": "string",
                                                "value": " AUTO_INCREMENT",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 702,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 702,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 703,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 705,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 705,
                                    "char": 19
                                },
                                "name": "isFirst",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 705,
                                "char": 30
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
                                                "type": "string",
                                                "value": " FIRST",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 706,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 706,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 707,
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
                                            "variable": "afterPosition",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 708,
                                                    "char": 40
                                                },
                                                "name": "getAfterPosition",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 708,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 708,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 710,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "afterPosition",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 710,
                                        "char": 30
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": " AFTER `",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 711,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "afterPosition",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 711,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 711,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "`",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 711,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 711,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 711,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 712,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 713,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 715,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 715,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 716,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 670,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 670,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 669,
                    "last-line": 726,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 727,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "sqlQuery",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 729,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": " LOCK IN SHARE MODE",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 729,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 729,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 730,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a SQL modified with a LOCK IN SHARE MODE clause\n     *\n     *```php\n     * $sql = $dialect->sharedLock(\"SELECT * FROM robots\");\n     *\n     * echo $sql; \/\/ SELECT * FROM robots LOCK IN SHARE MODE\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 728,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 728,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 727,
                    "last-line": 740,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 741,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 741,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 741,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "schemaName",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 743,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "return",
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
                                                        "value": "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 744,
                                                        "char": 107
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 744,
                                                        "char": 119
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 744,
                                                    "char": 119
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "' AND `TABLE_SCHEMA` = '",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 744,
                                                    "char": 146
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 744,
                                                "char": 146
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "schemaName",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 744,
                                                "char": 159
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 744,
                                            "char": 159
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "'",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 744,
                                            "char": 162
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 744,
                                        "char": 162
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 745,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 747,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 747,
                                        "char": 104
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "tableName",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 747,
                                        "char": 116
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 747,
                                    "char": 116
                                },
                                "right": {
                                    "type": "string",
                                    "value": "' AND `TABLE_SCHEMA` = DATABASE()",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 747,
                                    "char": 151
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 747,
                                "char": 151
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 748,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL checking for the existence of a schema.table\n     *\n     * ```php\n     * echo $dialect->tableExists(\"posts\", \"blog\");\n     *\n     * echo $dialect->tableExists(\"posts\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 742,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 742,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 741,
                    "last-line": 752,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 753,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 753,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 753,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 755,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 757,
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
                                        "type": "string",
                                        "value": "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 757,
                                        "char": 201
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 757,
                                    "char": 201
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 759,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "schema",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 759,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "return",
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
                                                            "type": "variable",
                                                            "value": "sql",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 760,
                                                            "char": 24
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "TABLES.TABLE_SCHEMA = '",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 760,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 760,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "schema",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 760,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 760,
                                                    "char": 59
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "' AND TABLES.TABLE_NAME = '",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 760,
                                                    "char": 89
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 760,
                                                "char": 89
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "table",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 760,
                                                "char": 97
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 760,
                                            "char": 97
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "'",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 760,
                                            "char": 100
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 760,
                                        "char": 100
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 761,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 763,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "sql",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 763,
                                            "char": 20
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "TABLES.TABLE_SCHEMA = DATABASE() AND TABLES.TABLE_NAME = '",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 763,
                                            "char": 81
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 763,
                                        "char": 81
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "table",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 763,
                                        "char": 89
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 763,
                                    "char": 89
                                },
                                "right": {
                                    "type": "string",
                                    "value": "'",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 763,
                                    "char": 92
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 763,
                                "char": 92
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 764,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 754,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 754,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 753,
                    "last-line": 768,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "truncateTable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tableName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 769,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 769,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "table",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 771,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 773,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "schemaName",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 773,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "table",
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
                                                                "value": "`",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 774,
                                                                "char": 27
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "schemaName",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 774,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 774,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "`.`",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 774,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 774,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 774,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 774,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "`",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 774,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 774,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 774,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 775,
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
                                            "variable": "table",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "`",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 776,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tableName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 776,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 776,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "`",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 776,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 776,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 776,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 777,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 779,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "TRUNCATE TABLE ",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 779,
                                    "char": 32
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "table",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 779,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 779,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 780,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to truncate a table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 770,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 770,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 769,
                    "last-line": 784,
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
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 785,
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 785,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 785,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "schemaName",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 787,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "return",
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
                                                        "value": "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 788,
                                                        "char": 106
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "viewName",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 788,
                                                        "char": 117
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 788,
                                                    "char": 117
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "' AND `TABLE_SCHEMA`='",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 788,
                                                    "char": 142
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 788,
                                                "char": 142
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "schemaName",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 788,
                                                "char": 155
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 788,
                                            "char": 155
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "'",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 788,
                                            "char": 158
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 788,
                                        "char": 158
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 789,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 791,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 791,
                                        "char": 101
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "viewName",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 791,
                                        "char": 112
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 791,
                                    "char": 112
                                },
                                "right": {
                                    "type": "string",
                                    "value": "' AND `TABLE_SCHEMA` = DATABASE()",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 791,
                                    "char": 147
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 791,
                                "char": 147
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 792,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 786,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 786,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 785,
                    "last-line": 796,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getTableOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 797,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 799,
                                    "char": 20
                                },
                                {
                                    "variable": "engine",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 799,
                                    "char": 28
                                },
                                {
                                    "variable": "autoIncrement",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 799,
                                    "char": 43
                                },
                                {
                                    "variable": "tableCollation",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 799,
                                    "char": 59
                                },
                                {
                                    "variable": "collationParts",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 799,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 800,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "tableOptions",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 800,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 802,
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
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 802,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 802,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 802,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 802,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 802,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 802,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 803,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 804,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 806,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "tableOptions",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 806,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 806,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 811,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "engine",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 811,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 811,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "ENGINE",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 811,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 811,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 811,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "engine",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 812,
                                        "char": 23
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "tableOptions",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "ENGINE=",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 813,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "engine",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 813,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 813,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 813,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 814,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 815,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 820,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "autoIncrement",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 820,
                                    "char": 57
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 820,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "AUTO_INCREMENT",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 820,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 820,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 820,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "autoIncrement",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 821,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "tableOptions",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "AUTO_INCREMENT=",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 822,
                                                            "char": 54
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "autoIncrement",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 822,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 822,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 822,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 823,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 824,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 829,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "tableCollation",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 829,
                                    "char": 59
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 829,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "TABLE_COLLATION",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 829,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 829,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 829,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "tableCollation",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 830,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "collationParts",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "explode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "_",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 831,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 831,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "tableCollation",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 831,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 831,
                                                                "char": 63
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 831,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 831,
                                                    "char": 64
                                                },
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "tableOptions",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "DEFAULT CHARSET=",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 832,
                                                            "char": 55
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "collationParts",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 832,
                                                                "char": 71
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 832,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 832,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 832,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 832,
                                                    "char": 74
                                                },
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "tableOptions",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "COLLATE=",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 833,
                                                            "char": 47
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "tableCollation",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 833,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 833,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 833,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 834,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 835,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 837,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "join",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": " ",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 837,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 837,
                                        "char": 22
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "tableOptions",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 837,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 837,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 837,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 838,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates SQL to add the table creation options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 798,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 798,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 797,
                    "last-line": 843,
                    "char": 22
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkColumnSizeAndScale",
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 844,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 844,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "columnSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 846,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 848,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 848,
                                    "char": 19
                                },
                                "name": "getSize",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 848,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "columnSql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "(",
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 849,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 849,
                                                        "char": 40
                                                    },
                                                    "name": "getSize",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 849,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 849,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 849,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 851,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 851,
                                            "char": 23
                                        },
                                        "name": "getScale",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 851,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": ",",
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 852,
                                                                "char": 35
                                                            },
                                                            "right": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "column",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                    "line": 852,
                                                                    "char": 44
                                                                },
                                                                "name": "getScale",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                                "line": 852,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 852,
                                                            "char": 56
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ")",
                                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                            "line": 852,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 852,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 852,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 853,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "columnSql",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": ")",
                                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                        "line": 854,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                    "line": 854,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 855,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 856,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "columnSql",
                                            "expr": {
                                                "type": "string",
                                                "value": ")",
                                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                                "line": 857,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                            "line": 857,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 858,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 860,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "columnSql",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 860,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 861,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if the size and\/or scale are present and encloses those values\n     * in parentheses if need be\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 845,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 845,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 844,
                    "last-line": 865,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkColumnUnsigned",
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
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 866,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 866,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 868,
                                    "char": 19
                                },
                                "name": "isUnsigned",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 868,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": " UNSIGNED",
                                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                        "line": 869,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                    "line": 870,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 872,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 872,
                                "char": 16
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                            "line": 873,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a column is unsigned or not and returns the relevant SQL syntax\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                                "line": 867,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                        "line": 867,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
                    "line": 866,
                    "last-line": 874,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Dialect\/Mysql.zep",
        "line": 24,
        "char": 5
    }
]