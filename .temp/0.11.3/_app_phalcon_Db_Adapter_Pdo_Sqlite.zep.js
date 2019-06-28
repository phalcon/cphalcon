[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db\\Adapter\\Pdo",
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Adapter\\Pdo",
                "alias": "PdoAdapter",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 14,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Column",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 15,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ColumnInterface",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 16,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Exception",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 17,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Index",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 18,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\IndexInterface",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 19,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\RawValue",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 20,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Reference",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 21,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ReferenceInterface",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                "line": 22,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 36,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Specific functions for the Sqlite database system\n *\n * ```php\n * use Phalcon\\Db\\Adapter\\Pdo\\Sqlite;\n *\n * $connection = new Sqlite(\n *     [\n *         \"dbname\" => \"\/tmp\/test.sqlite\",\n *     ]\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 37,
        "char": 5
    },
    {
        "type": "class",
        "name": "Sqlite",
        "abstract": 0,
        "final": 0,
        "extends": "PdoAdapter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "dialectType",
                    "default": {
                        "type": "string",
                        "value": "sqlite",
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 42,
                        "char": 35
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "default": {
                        "type": "string",
                        "value": "sqlite",
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 47,
                        "char": 28
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 51,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 52,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "descriptor",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 54,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "charset",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 54,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 54,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 54,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "trigger_error",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Sqlite does not allow the charset to be changed in the DSN.",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 57,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 57,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 57,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 58,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 60,
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
                                            "value": "descriptor",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 60,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 60,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 60,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor for Phalcon\\Db\\Adapter\\Pdo\\Sqlite\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 53,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 52,
                    "last-line": 66,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 67,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 67,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dbname",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 69,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 71,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "descriptor",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 71,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 71,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "descriptor",
                                            "expr": {
                                                "type": "cast",
                                                "left": "array",
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 72,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "descriptor",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 72,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 72,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 72,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 72,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 75,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "dbname",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 75,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "descriptor",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 75,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "dbname",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 75,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 75,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 75,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "descriptor",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "dsn",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 76,
                                                    "char": 31
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "dbname",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 76,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 76,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 78,
                                    "char": 17
                                },
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "descriptor",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 78,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "dbname",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 78,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 78,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 79,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
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
                                                        "value": "descriptor",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 79,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "dsn",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 79,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 79,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 79,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 79,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 79,
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
                                                            "value": "The database must be specified with either 'dbname' or 'dsn'.",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 82,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 82,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 82,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 83,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 85,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 85,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "connect",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "descriptor",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 85,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 85,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 85,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 86,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * This method is automatically called in Phalcon\\Db\\Adapter\\Pdo\n     * constructor. Call it when you need to restore a database connection.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 68,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 68,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 67,
                    "last-line": 96,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 97,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 97,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 97,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 99,
                                    "char": 20
                                },
                                {
                                    "variable": "columnType",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 99,
                                    "char": 32
                                },
                                {
                                    "variable": "fields",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 99,
                                    "char": 40
                                },
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 99,
                                    "char": 47
                                },
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 99,
                                    "char": 59
                                },
                                {
                                    "variable": "oldColumn",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 99,
                                    "char": 70
                                },
                                {
                                    "variable": "sizePattern",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 100,
                                    "char": 24
                                },
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 100,
                                    "char": 33
                                },
                                {
                                    "variable": "matchOne",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 100,
                                    "char": 43
                                },
                                {
                                    "variable": "matchTwo",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 100,
                                    "char": 53
                                },
                                {
                                    "variable": "columnName",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 100,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 102,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "oldColumn",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 102,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 102,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sizePattern",
                                    "expr": {
                                        "type": "string",
                                        "value": "#\\\\(([0-9]+)(?:,\\\\s*([0-9]+))*\\\\)#",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 103,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 103,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
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
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 105,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 105,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 110,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fields",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 110,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 111,
                                                            "char": 18
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "dialect",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 111,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 111,
                                                        "char": 27
                                                    },
                                                    "name": "describeColumns",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "table",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 111,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 111,
                                                            "char": 49
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "schema",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 111,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 111,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 111,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 111,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Db",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 113,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "FETCH_NUM",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 113,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 113,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 113,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 113,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 113,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 115,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "fields",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 115,
                                "char": 29
                            },
                            "value": "field",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "bindType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 121,
                                                            "char": 25
                                                        },
                                                        "value": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Column",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 122,
                                                                "char": 13
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "BIND_PARAM_STR",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 122,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 122,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 122,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 122,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 122,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 128,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnType",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 128,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 128,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 128,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 128,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 143,
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
                                                    "type": "variable",
                                                    "value": "columnType",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 143,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 143,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "bigint",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 143,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 143,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 143,
                                        "char": 43
                                    },
                                    "statements": [
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
                                                            "value": "type",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 147,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Column",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 147,
                                                            "char": 63
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "TYPE_BIGINTEGER",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 147,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 147,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 147,
                                                    "char": 63
                                                },
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "definition",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "isNumeric",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 148,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 148,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 148,
                                                    "char": 49
                                                },
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "definition",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "bindType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 149,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Column",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 149,
                                                            "char": 66
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "BIND_PARAM_INT",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 149,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 149,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 149,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 150,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "or",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "memstr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "columnType",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 150,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 150,
                                                            "char": 39
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "int",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 150,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 150,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 150,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "memstr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "columnType",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 150,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 150,
                                                            "char": 66
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "INT",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 150,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 150,
                                                            "char": 71
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 150,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 150,
                                                "char": 73
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 154,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 154,
                                                                    "char": 60
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_INTEGER",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 154,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 154,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 154,
                                                            "char": 60
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 155,
                                                                    "char": 41
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 155,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 155,
                                                            "char": 49
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 156,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 156,
                                                                    "char": 66
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 156,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 156,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 156,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 158,
                                                    "char": 18
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 158,
                                                            "char": 25
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "5",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 158,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 158,
                                                        "char": 29
                                                    },
                                                    "statements": [
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
                                                                            "value": "autoIncrement",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 159,
                                                                            "char": 49
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 159,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 159,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 160,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 161,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 161,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 161,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 161,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "tinyint(1)",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 161,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 161,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 161,
                                                "char": 53
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 165,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 165,
                                                                    "char": 60
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BOOLEAN",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 165,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 165,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 165,
                                                            "char": 60
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 166,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 166,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_BOOL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 166,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 166,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 166,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "columnType",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "boolean",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 167,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 167,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 172,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 172,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 172,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 172,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "enum",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 172,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 172,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 172,
                                                "char": 47
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 176,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 176,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_CHAR",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 176,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 176,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 176,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 181,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 181,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 181,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 181,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "datetime",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 181,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 181,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 181,
                                                "char": 51
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 185,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 185,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DATETIME",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 185,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 185,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 185,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 186,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 186,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 186,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 186,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "date",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 186,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 186,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 186,
                                                "char": 47
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 190,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 190,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DATE",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 190,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 190,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 190,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 195,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 195,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 195,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 195,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "decimal",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 195,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 195,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 195,
                                                "char": 50
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 199,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 199,
                                                                    "char": 60
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 199,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 199,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 199,
                                                            "char": 60
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 200,
                                                                    "char": 41
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 200,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 200,
                                                            "char": 49
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 201,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 201,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 201,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 201,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 201,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 202,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 202,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 202,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 202,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "float",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 202,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 202,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 202,
                                                "char": 48
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 206,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 206,
                                                                    "char": 58
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_FLOAT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 206,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 206,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 206,
                                                            "char": 58
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 207,
                                                                    "char": 41
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 207,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 207,
                                                            "char": 49
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 208,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 208,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 208,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 208,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 208,
                                                            "char": 64
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 213,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 213,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 213,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 213,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "timestamp",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 213,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 213,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 213,
                                                "char": 52
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 217,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 217,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TIMESTAMP",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 217,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 217,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 217,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 222,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 222,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 222,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 222,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "varchar",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 222,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 222,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 222,
                                                "char": 50
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 226,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 226,
                                                                    "char": 60
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_VARCHAR",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 226,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 226,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 226,
                                                            "char": 60
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 227,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 227,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 227,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 227,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "char",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 227,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 227,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 227,
                                                "char": 47
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 231,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 231,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_CHAR",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 231,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 231,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 231,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 232,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 232,
                                            "char": 20
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
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 232,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 232,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 232,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 232,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 232,
                                                "char": 47
                                            },
                                            "statements": [
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 236,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 236,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TEXT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 236,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 236,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 236,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 238,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 238,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
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
                                                            "value": "type",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 242,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Column",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 242,
                                                            "char": 60
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "TYPE_VARCHAR",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 242,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 242,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 242,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 243,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 249,
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
                                                    "type": "variable",
                                                    "value": "columnType",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 249,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 249,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "(",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 249,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 249,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 249,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "matches",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 250,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 250,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 252,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "preg_match",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sizePattern",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 252,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 252,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 252,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 252,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "matches",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 252,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 252,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 252,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "matchOne",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 253,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "matches",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 253,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 253,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 253,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 253,
                                                        "char": 51
                                                    },
                                                    "statements": [
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
                                                                            "value": "size",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 254,
                                                                            "char": 44
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "cast",
                                                                        "left": "int",
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "matchOne",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 254,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 254,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 254,
                                                                    "char": 62
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 255,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 256,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "matchTwo",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 256,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "matches",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 256,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "2",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 256,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 256,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 256,
                                                        "char": 51
                                                    },
                                                    "statements": [
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
                                                                            "value": "scale",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 257,
                                                                            "char": 45
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "cast",
                                                                        "left": "int",
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "matchTwo",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 257,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 257,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 257,
                                                                    "char": 63
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 258,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 259,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 260,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 265,
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
                                                    "type": "variable",
                                                    "value": "columnType",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 265,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 265,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "unsigned",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 265,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 265,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 265,
                                        "char": 45
                                    },
                                    "statements": [
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
                                                            "value": "unsigned",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 266,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 266,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 266,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 267,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 272,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "oldColumn",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 272,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 272,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 272,
                                        "char": 34
                                    },
                                    "statements": [
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
                                                            "value": "first",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 273,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 273,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 273,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 274,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
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
                                                            "value": "after",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 275,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "oldColumn",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 275,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 275,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 276,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 281,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 281,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "5",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 281,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 281,
                                        "char": 25
                                    },
                                    "statements": [
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
                                                            "value": "primary",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 282,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 282,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 282,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 283,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 288,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 288,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "3",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 288,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 288,
                                        "char": 25
                                    },
                                    "statements": [
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
                                                            "value": "notNull",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 289,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 289,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 289,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 290,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 296,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strcasecmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 296,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "4",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 296,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 296,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 296,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "null",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 296,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 296,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 296,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 296,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 296,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 296,
                                                    "char": 56
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 296,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 296,
                                                "char": 61
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 296,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 296,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 296,
                                        "char": 64
                                    },
                                    "statements": [
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
                                                            "value": "default",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 297,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "preg_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/^'|'$\/",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 298,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 298,
                                                                "char": 28
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 299,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 299,
                                                                "char": 21
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "field",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 300,
                                                                        "char": 26
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "4",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 300,
                                                                        "char": 28
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 301,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 301,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 301,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 301,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 302,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 307,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnName",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 307,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 307,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 307,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 307,
                                            "char": 38
                                        },
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "columns",
                                            "expr": {
                                                "type": "new",
                                                "class": "Column",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnName",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 308,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 308,
                                                        "char": 50
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "definition",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 308,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 308,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 308,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 308,
                                            "char": 63
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "oldColumn",
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnName",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 309,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 309,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 310,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 312,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "columns",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 312,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 313,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of Phalcon\\Db\\Column objects describing a table\n     *\n     * ```php\n     * print_r(\n     *     $connection->describeColumns(\"posts\")\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ColumnInterface",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 98,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 98,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 98,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 97,
                    "last-line": 323,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 324,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 324,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 324,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "indexes",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 326,
                                    "char": 20
                                },
                                {
                                    "variable": "index",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 326,
                                    "char": 27
                                },
                                {
                                    "variable": "keyName",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 326,
                                    "char": 36
                                },
                                {
                                    "variable": "indexObjects",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 326,
                                    "char": 50
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 326,
                                    "char": 56
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 326,
                                    "char": 65
                                },
                                {
                                    "variable": "describeIndexes",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 327,
                                    "char": 28
                                },
                                {
                                    "variable": "describeIndex",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 327,
                                    "char": 43
                                },
                                {
                                    "variable": "indexSql",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 327,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 329,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 329,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 329,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 331,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 331,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 331,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 331,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 331,
                                                "char": 51
                                            },
                                            "name": "describeIndexes",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 331,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 331,
                                                    "char": 73
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schema",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 331,
                                                        "char": 81
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 331,
                                                    "char": 81
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 331,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 331,
                                        "char": 82
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Db",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 331,
                                                "char": 99
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "FETCH_ASSOC",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 331,
                                                "char": 99
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 331,
                                            "char": 99
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 331,
                                        "char": 99
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 331,
                                "char": 101
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 332,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 332,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 332,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 332,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 334,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 334,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "keyName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 334,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 334,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 334,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 334,
                                        "char": 40
                                    },
                                    "statements": [
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 335,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 335,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 335,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 336,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 338,
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
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "indexes",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 338,
                                                        "char": 30
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "keyName",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 338,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 338,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "columns",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 338,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 338,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 338,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 338,
                                        "char": 49
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
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 339,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 339,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 340,
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
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "indexes",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 341,
                                                                "char": 38
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "keyName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 341,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 341,
                                                            "char": 47
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 341,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 341,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 341,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 342,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 344,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "describeIndexes",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 344,
                                                    "char": 40
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 345,
                                                                    "char": 22
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "dialect",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 345,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 345,
                                                                "char": 31
                                                            },
                                                            "name": "describeIndex",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "keyName",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 345,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 345,
                                                                    "char": 53
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 345,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 345,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Db",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 347,
                                                                "char": 13
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "FETCH_ASSOC",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 347,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 347,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 347,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 347,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 347,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 349,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "describeIndexes",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 349,
                                        "char": 50
                                    },
                                    "value": "describeIndex",
                                    "reverse": 0,
                                    "statements": [
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
                                                            "value": "describeIndex",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 350,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 350,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 350,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 350,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 351,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 353,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 353,
                                                    "char": 32
                                                },
                                                {
                                                    "type": "string",
                                                    "value": "columns",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 353,
                                                    "char": 41
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 353,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 353,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 355,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "indexSql",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 355,
                                                    "char": 33
                                                },
                                                "name": "fetchColumn",
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 356,
                                                                    "char": 22
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "dialect",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 356,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 356,
                                                                "char": 31
                                                            },
                                                            "name": "listIndexesSql",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "table",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 356,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 356,
                                                                    "char": 52
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "schema",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 356,
                                                                        "char": 60
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 356,
                                                                    "char": 60
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "keyName",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 356,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 356,
                                                                    "char": 69
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 357,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 357,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 357,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 357,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 359,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 359,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "unique",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 359,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 359,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "preg_match",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "# UNIQUE #i",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 360,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 360,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "indexSql",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 360,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 360,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 360,
                                                "char": 54
                                            },
                                            "statements": [
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 361,
                                                                    "char": 40
                                                                },
                                                                {
                                                                    "type": "string",
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 361,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "UNIQUE",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 361,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 361,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 362,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 363,
                                                                    "char": 40
                                                                },
                                                                {
                                                                    "type": "string",
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 363,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "PRIMARY",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 363,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 363,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 364,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 365,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 366,
                                                            "char": 36
                                                        },
                                                        {
                                                            "type": "string",
                                                            "value": "type",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 366,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 366,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 366,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 367,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 368,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 370,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 370,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 370,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 372,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "indexes",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 372,
                                "char": 36
                            },
                            "key": "name",
                            "value": "index",
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 373,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 374,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 374,
                                                        "char": 21
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "index",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 375,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "columns",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 375,
                                                                "char": 30
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 375,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 375,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "index",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 376,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "type",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 376,
                                                                "char": 27
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 377,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 377,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 377,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 377,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 378,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 380,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "indexObjects",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 380,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 381,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Lists table indexes\n     *\n     * ```php\n     * print_r(\n     *     $connection->describeIndexes(\"robots_parts\")\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "IndexInterface",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 325,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 325,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 325,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 324,
                    "last-line": 385,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 386,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 386,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 386,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 388,
                                    "char": 23
                                },
                                {
                                    "variable": "reference",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 388,
                                    "char": 34
                                },
                                {
                                    "variable": "arrayReference",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 388,
                                    "char": 50
                                },
                                {
                                    "variable": "constraintName",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 388,
                                    "char": 66
                                },
                                {
                                    "variable": "referenceObjects",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 389,
                                    "char": 29
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 389,
                                    "char": 35
                                },
                                {
                                    "variable": "referencedSchema",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 389,
                                    "char": 53
                                },
                                {
                                    "variable": "referencedTable",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 389,
                                    "char": 70
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 389,
                                    "char": 79
                                },
                                {
                                    "variable": "referencedColumns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 390,
                                    "char": 30
                                },
                                {
                                    "variable": "number",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 390,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 392,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 392,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 392,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 394,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 394,
                                    "char": 39
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 394,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 394,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 394,
                                                "char": 63
                                            },
                                            "name": "describeReferences",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 394,
                                                        "char": 88
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 394,
                                                    "char": 88
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schema",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 394,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 394,
                                                    "char": 96
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 394,
                                            "char": 97
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 394,
                                        "char": 97
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Db",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 394,
                                                "char": 112
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "FETCH_NUM",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 394,
                                                "char": 112
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 394,
                                            "char": 112
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 394,
                                        "char": 112
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 394,
                                "char": 114
                            },
                            "key": "number",
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
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "foreign_key_",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 395,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "number",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 395,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 395,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 395,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 397,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 397,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "constraintName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 397,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 397,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 397,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 397,
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
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 398,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 398,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 399,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 399,
                                                            "char": 48
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "2",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 399,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 399,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 399,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 400,
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
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 400,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 400,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 401,
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
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 401,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 401,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 402,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 403,
                                                                "char": 50
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 403,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 403,
                                                            "char": 66
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedSchema",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 403,
                                                            "char": 83
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 403,
                                                        "char": 84
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 403,
                                                    "char": 84
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 404,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 404,
                                                                "char": 49
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 404,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 404,
                                                            "char": 65
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 404,
                                                            "char": 81
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 404,
                                                        "char": 82
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 404,
                                                    "char": 82
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 405,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 405,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 405,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 405,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 405,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 405,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 405,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 406,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 406,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                "line": 406,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 406,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 406,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 406,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 406,
                                                    "char": 86
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 407,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 409,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 409,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "3",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 409,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 409,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 409,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 410,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 410,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 410,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 410,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 412,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 412,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 413,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedSchema",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 413,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 413,
                                                        "char": 53
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 414,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 414,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 414,
                                                        "char": 52
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 415,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 415,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 415,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 416,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 417,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 417,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 417,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 417,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 418,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 420,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 420,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 420,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 422,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "references",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 422,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                    "line": 423,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 424,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 424,
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
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 426,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 426,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedSchema",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 426,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 426,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 426,
                                                                    "char": 73
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "referencedTable",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 427,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 427,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedTable",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 427,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 427,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 427,
                                                                    "char": 72
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "columns",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 428,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 428,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "columns",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 428,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 428,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 428,
                                                                    "char": 64
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "referencedColumns",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 429,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 429,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedColumns",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                            "line": 429,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                        "line": 430,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                                    "line": 430,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                            "line": 431,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                        "line": 431,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                                "line": 431,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 431,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 432,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 434,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "referenceObjects",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 434,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 435,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 387,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 387,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 387,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 386,
                    "last-line": 455,
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
                                            "value": "NULL",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                            "line": 458,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                        "line": 458,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 458,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 459,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default value to make the RBDM use the default value declared\n     * in the table definition\n     *\n     *```php\n     * \/\/ Inserting a new robot with a valid default value for the column 'year'\n     * $success = $connection->insert(\n     *     \"robots\",\n     *     [\n     *         \"Astro Boy\",\n     *         $connection->getDefaultValue(),\n     *     ],\n     *     [\n     *         \"name\",\n     *         \"year\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RawValue",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                    "line": 457,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 457,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 457,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 456,
                    "last-line": 464,
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
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 467,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 468,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 466,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 466,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 465,
                    "last-line": 472,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getDsnDefaults",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 475,
                                "char": 18
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                            "line": 476,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns PDO adapter DSN defaults as a key-value map.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                                "line": 474,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                        "line": 474,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
                    "line": 473,
                    "last-line": 477,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
            "line": 37,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Sqlite.zep",
        "line": 37,
        "char": 5
    }
]