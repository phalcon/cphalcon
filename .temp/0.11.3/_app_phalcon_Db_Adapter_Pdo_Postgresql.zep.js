[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db\\Adapter\\Pdo",
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Adapter\\Pdo",
                "alias": "PdoAdapter",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 14,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Column",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 15,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ColumnInterface",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 16,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Exception",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 17,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\RawValue",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 18,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Reference",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 19,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ReferenceInterface",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 20,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Throwable",
                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                "line": 21,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 39,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Specific functions for the Postgresql database system\n *\n * ```php\n * use Phalcon\\Db\\Adapter\\Pdo\\Postgresql;\n *\n * $config = [\n *     \"host\"     => \"localhost\",\n *     \"dbname\"   => \"blog\",\n *     \"port\"     => 5432,\n *     \"username\" => \"postgres\",\n *     \"password\" => \"secret\",\n * ];\n *\n * $connection = new Postgresql($config);\n * ```\n *",
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 40,
        "char": 5
    },
    {
        "type": "class",
        "name": "Postgresql",
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
                        "value": "postgresql",
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 45,
                        "char": 39
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 49,
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
                        "value": "pgsql",
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 50,
                        "char": 27
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 54,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 55,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 57,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "charset",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 57,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 57,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 57,
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
                                                    "value": "Postgres does not allow the charset to be changed in the DSN.",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 60,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 60,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 60,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 61,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 63,
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
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 63,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 63,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 63,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 64,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor for Phalcon\\Db\\Adapter\\Pdo\\Postgresql\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 56,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 55,
                    "last-line": 69,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 70,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 70,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "schema",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 72,
                                    "char": 19
                                },
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 72,
                                    "char": 24
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 72,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 74,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "descriptor",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 74,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 74,
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
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 75,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "descriptor",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 75,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 75,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 75,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 75,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 78,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "schema",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 78,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "descriptor",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 78,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "schema",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 78,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 78,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 78,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "descriptor",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 79,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "schema",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 79,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 79,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 80,
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
                                            "variable": "schema",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 81,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 81,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 84,
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
                                        "value": "descriptor",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 84,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "password",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 84,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 84,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 84,
                                "char": 39
                            },
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
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "descriptor",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 85,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "password",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 85,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 85,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 85,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 85,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 85,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strlen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "descriptor",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 85,
                                                                "char": 74
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "password",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 85,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 85,
                                                            "char": 84
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 85,
                                                        "char": 84
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 85,
                                                "char": 87
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 85,
                                                "char": 91
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 85,
                                            "char": 91
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 85,
                                        "char": 91
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
                                                            "value": "password",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 86,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 86,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 86,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 87,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 88,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 90,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 90,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 90,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 90,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 90,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 92,
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
                                        "value": "schema",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 92,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 92,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 92,
                                "char": 26
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
                                                        "value": "SET search_path TO '",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 93,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "schema",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 93,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 93,
                                                    "char": 53
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "'",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 93,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 93,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 93,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 95,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 95,
                                            "char": 18
                                        },
                                        "name": "execute",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sql",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 95,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 95,
                                                "char": 30
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 95,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 96,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "status",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 98,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 99,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 71,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 70,
                    "last-line": 103,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 104,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 104,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 104,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 106,
                                    "char": 16
                                },
                                {
                                    "variable": "queries",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 106,
                                    "char": 25
                                },
                                {
                                    "variable": "query",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 106,
                                    "char": 32
                                },
                                {
                                    "variable": "exception",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 106,
                                    "char": 43
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 106,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 108,
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
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 108,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 108,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 108,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 108,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 108,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 108,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 108,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 109,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 109,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 109,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 110,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 112,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 112,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 112,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 112,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 112,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 112,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 113,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 113,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 113,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 116,
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
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 116,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "dialect",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 116,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 116,
                                            "char": 33
                                        },
                                        "name": "createTable",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tableName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 116,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 116,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 116,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 116,
                                                "char": 67
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "definition",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 116,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 116,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 116,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 116,
                                    "char": 80
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 118,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "queries",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ";",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 118,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 118,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sql",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 118,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 118,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 118,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 118,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 120,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "queries",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 120,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 120,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 120,
                                    "char": 27
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 120,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 120,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "try-catch",
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 122,
                                                    "char": 22
                                                },
                                                "name": "begin",
                                                "call-type": 3,
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 122,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 124,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "queries",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 124,
                                                "char": 38
                                            },
                                            "value": "query",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "empty",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "query",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 125,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 125,
                                                        "char": 36
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 127,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 129,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 129,
                                                            "char": 26
                                                        },
                                                        "name": "query",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "query",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 129,
                                                                        "char": 41
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": ";",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 129,
                                                                        "char": 44
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 129,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 129,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 129,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 130,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 132,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 132,
                                                    "char": 29
                                                },
                                                "name": "commit",
                                                "call-type": 3,
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 132,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 133,
                                            "char": 13
                                        }
                                    ],
                                    "catches": [
                                        {
                                            "classes": [
                                                {
                                                    "type": "variable",
                                                    "value": "Throwable",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 133,
                                                    "char": 30
                                                }
                                            ],
                                            "variable": {
                                                "type": "variable",
                                                "value": "exception",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 138,
                                                "char": 9
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 134,
                                                            "char": 22
                                                        },
                                                        "name": "rollback",
                                                        "call-type": 3,
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 134,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 136,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "throw",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "exception",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 136,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 137,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 138,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 138,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 139,
                                            "char": 25
                                        },
                                        "name": "execute",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "queries",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 139,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 139,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 139,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": ";",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 139,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 139,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 139,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 139,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 140,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 142,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 142,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 143,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 105,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 105,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 104,
                    "last-line": 153,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 154,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 154,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 154,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 156,
                                    "char": 20
                                },
                                {
                                    "variable": "columnType",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 156,
                                    "char": 32
                                },
                                {
                                    "variable": "fields",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 156,
                                    "char": 40
                                },
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 156,
                                    "char": 47
                                },
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 156,
                                    "char": 59
                                },
                                {
                                    "variable": "oldColumn",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 156,
                                    "char": 70
                                },
                                {
                                    "variable": "columnName",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 157,
                                    "char": 23
                                },
                                {
                                    "variable": "charSize",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 157,
                                    "char": 33
                                },
                                {
                                    "variable": "numericSize",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 157,
                                    "char": 46
                                },
                                {
                                    "variable": "numericScale",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 157,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 159,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 159,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 159,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columns",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 159,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 159,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 166,
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
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 166,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 167,
                                                            "char": 18
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "dialect",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 167,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 167,
                                                        "char": 27
                                                    },
                                                    "name": "describeColumns",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "table",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 167,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 167,
                                                            "char": 49
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "schema",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 167,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 167,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 167,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 167,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Db",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 169,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "FETCH_NUM",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 169,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 169,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 169,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 169,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 169,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 171,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "fields",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 171,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 177,
                                                            "char": 25
                                                        },
                                                        "value": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Column",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 178,
                                                                "char": 13
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "BIND_PARAM_STR",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 178,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 178,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 178,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 178,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 178,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 184,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 184,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 184,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 184,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 184,
                                            "char": 38
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "charSize",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 185,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 185,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 185,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 185,
                                            "char": 36
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "numericSize",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 186,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "3",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 186,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 186,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 186,
                                            "char": 39
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "numericScale",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 187,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 187,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 187,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 187,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 201,
                                    "char": 18
                                },
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 201,
                                        "char": 25
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 205,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 205,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "boolean",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 205,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 205,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 205,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 209,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 209,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BOOLEAN",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 209,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 209,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 209,
                                                            "char": 64
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 210,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 210,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 210,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 211,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 211,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_BOOL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 211,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 211,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 211,
                                                            "char": 71
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 213,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 218,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 218,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 218,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 218,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "bigint",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 218,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 218,
                                                        "char": 47
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 218,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 219,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 219,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BIGINTEGER",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 219,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 219,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 219,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 220,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 220,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 220,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 221,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 221,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 221,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 221,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 221,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 223,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 228,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 228,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 228,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 228,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "mediumint",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 228,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 228,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 228,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 229,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 229,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_MEDIUMINTEGER",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 229,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 229,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 229,
                                                            "char": 70
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 230,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 230,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 230,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 231,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 231,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 231,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 231,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 231,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 233,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 238,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 238,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 238,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 238,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "smallint",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 238,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 238,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 238,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 239,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 239,
                                                                    "char": 69
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_SMALLINTEGER",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 239,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 239,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 239,
                                                            "char": 69
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 240,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 240,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 240,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 241,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 241,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 241,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 241,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 241,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 243,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 248,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 248,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 248,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 248,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "tinyint",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 248,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 248,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 248,
                                                "char": 49
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 252,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 252,
                                                                    "char": 68
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TINYINTEGER",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 252,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 252,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 252,
                                                            "char": 68
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 253,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 253,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 253,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 254,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 254,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 254,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 254,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 254,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 256,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 261,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 261,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 261,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 261,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "int",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 261,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 261,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 261,
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 262,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 262,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_INTEGER",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 262,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 262,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 262,
                                                            "char": 64
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 263,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 263,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 263,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 264,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 264,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 264,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 264,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 264,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 266,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 271,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 271,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 271,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 271,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "bit",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 271,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 271,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 271,
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
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 272,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 272,
                                                                    "char": 60
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BIT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 272,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 272,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 272,
                                                            "char": 60
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 273,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "numericSize",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 273,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 273,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 275,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 280,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 280,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 280,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 280,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "enum",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 280,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 280,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 280,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 281,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 281,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_ENUM",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 281,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 281,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 281,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 283,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 288,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 288,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 288,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 288,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "datetime",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 288,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 288,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 288,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 289,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 289,
                                                                    "char": 65
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DATETIME",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 289,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 289,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 289,
                                                            "char": 65
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 290,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 290,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 290,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 292,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 297,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 297,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 297,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 297,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "date",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 297,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 297,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 297,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 298,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 298,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DATE",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 298,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 298,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 298,
                                                            "char": 61
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 299,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 299,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 299,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 301,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 307,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 307,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 307,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 307,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "decimal",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 307,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 307,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 307,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 308,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 308,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 308,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "numeric",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 308,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 308,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 308,
                                                "char": 49
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 309,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 309,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 309,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 309,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 309,
                                                            "char": 64
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 310,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "numericSize",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 310,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 310,
                                                            "char": 55
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 311,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 311,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 311,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 312,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 312,
                                                                    "char": 74
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 312,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 312,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 312,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 314,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 319,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 319,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 319,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 319,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "double precision",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 319,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 319,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 319,
                                                "char": 58
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 320,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 320,
                                                                    "char": 63
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DOUBLE",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 320,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 320,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 320,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 321,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 321,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 321,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 322,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "numericSize",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 322,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 322,
                                                            "char": 55
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 323,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 323,
                                                                    "char": 74
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 323,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 323,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 323,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 325,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 330,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 330,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 330,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 330,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "float",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 330,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 330,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 330,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 331,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 331,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 331,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "real",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 331,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 331,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 331,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 332,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 332,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_FLOAT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 332,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 332,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 332,
                                                            "char": 62
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "isNumeric",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 333,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 333,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 333,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 334,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "numericSize",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 334,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 334,
                                                            "char": 55
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "bindType",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 335,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 335,
                                                                    "char": 74
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 335,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 335,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 335,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 337,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 342,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 342,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 342,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 342,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "mediumblob",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 342,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 342,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 342,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 343,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 343,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TEXT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 343,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 343,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 343,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 345,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 350,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 350,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 350,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 350,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "longblob",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 350,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 350,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 350,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 351,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 351,
                                                                    "char": 65
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_LONGBLOB",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 351,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 351,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 351,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 353,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 358,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 358,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 358,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 358,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "tinyblob",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 358,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 358,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 358,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 359,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 359,
                                                                    "char": 65
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TINYBLOB",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 359,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 359,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 359,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 361,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 366,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 366,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 366,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 366,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "blob",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 366,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 366,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 366,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 367,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 367,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BLOB",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 367,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 367,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 367,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 369,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 374,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 374,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 374,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 374,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "timestamp",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 374,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 374,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 374,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 375,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 375,
                                                                    "char": 66
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TIMESTAMP",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 375,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 375,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 375,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 377,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 382,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 382,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 382,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 382,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "time",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 382,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 382,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 382,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 383,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 383,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TIME",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 383,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 383,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 383,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 385,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 390,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 390,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 390,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 390,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "jsonb",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 390,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 390,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 390,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 391,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 391,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_JSONB",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 391,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 391,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 391,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 393,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 398,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 398,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 398,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 398,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "json",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 398,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 398,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 398,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 399,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 399,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_JSON",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 399,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 399,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 399,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 401,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 406,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 406,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 406,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 406,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "longtext",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 406,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 406,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 406,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 407,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 407,
                                                                    "char": 65
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_LONGTEXT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 407,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 407,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 407,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 409,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 414,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 414,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 414,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 414,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "mediumtext",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 414,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 414,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 414,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 415,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 415,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_MEDIUMTEXT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 415,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 415,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 415,
                                                            "char": 67
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 417,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 422,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 422,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 422,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 422,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "tinytext",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 422,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 422,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 422,
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 423,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 423,
                                                                    "char": 65
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TINYTEXT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 423,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 423,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 423,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 425,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 430,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 430,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 430,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 430,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 430,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 430,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 430,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 431,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 431,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TEXT",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 431,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 431,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 431,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 433,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 438,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 438,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 438,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 438,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "varying",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 438,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 438,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 438,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 439,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 439,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 439,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "varchar",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 439,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 439,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 439,
                                                "char": 49
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 440,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 440,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_VARCHAR",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 440,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 440,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 440,
                                                            "char": 64
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 441,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "charSize",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 441,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 441,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 443,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 448,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 448,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 448,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 448,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "char",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 448,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 448,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 448,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 449,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 449,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_CHAR",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 449,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 449,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 449,
                                                            "char": 61
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 450,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "charSize",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 450,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 450,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 452,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 457,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 457,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "memstr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "columnType",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 457,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 457,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "uuid",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 457,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 457,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 457,
                                                "char": 46
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 458,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 458,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_CHAR",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 458,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 458,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 458,
                                                            "char": 61
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "definition",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 459,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "int",
                                                                "value": "36",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 459,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 459,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 461,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 466,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 466,
                                            "char": 23
                                        },
                                        {
                                            "type": "default",
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 467,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 467,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_VARCHAR",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 467,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 467,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 467,
                                                            "char": 64
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 469,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 470,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 470,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 475,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "oldColumn",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 475,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 475,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 475,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 476,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 476,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 476,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 477,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 478,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "oldColumn",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 478,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 478,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 479,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 484,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 484,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "6",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 484,
                                                "char": 23
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 484,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "PRI",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 484,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 484,
                                        "char": 32
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 485,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 485,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 485,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 486,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 491,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 491,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "5",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 491,
                                                "char": 23
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 491,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "NO",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 491,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 491,
                                        "char": 31
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 492,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 492,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 492,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 493,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 498,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 498,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "7",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 498,
                                                "char": 23
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 498,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "auto_increment",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 498,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 498,
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
                                                            "value": "autoIncrement",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 499,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 499,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 499,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 500,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 505,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 505,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "9",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 505,
                                                "char": 23
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 505,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 505,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 505,
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
                                                            "value": "default",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 506,
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
                                                                    "value": "\/^'|'?::[[:alnum:][:space:]]+$\/",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 507,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 507,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 508,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 508,
                                                                "char": 21
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "field",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 509,
                                                                        "char": 26
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "9",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 509,
                                                                        "char": 28
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 510,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 510,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 510,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 510,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 512,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
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
                                                                    "value": "definition",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 512,
                                                                    "char": 41
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "default",
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 512,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 512,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 512,
                                                            "char": 50
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "null",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 512,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 512,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 512,
                                                    "char": 59
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 512,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 512,
                                                "char": 63
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
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 513,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "null",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 513,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 513,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 514,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 515,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 520,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 520,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 520,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 520,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 520,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 521,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 521,
                                                        "char": 50
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "definition",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 521,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 521,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 521,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 521,
                                            "char": 63
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "oldColumn",
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnName",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 522,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 522,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 523,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 525,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "columns",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 525,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 526,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 155,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 155,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 155,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 154,
                    "last-line": 536,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 537,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 537,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 537,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 539,
                                    "char": 23
                                },
                                {
                                    "variable": "reference",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 539,
                                    "char": 34
                                },
                                {
                                    "variable": "arrayReference",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 539,
                                    "char": 50
                                },
                                {
                                    "variable": "constraintName",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 539,
                                    "char": 66
                                },
                                {
                                    "variable": "referenceObjects",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 540,
                                    "char": 29
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 540,
                                    "char": 35
                                },
                                {
                                    "variable": "referencedSchema",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 540,
                                    "char": 53
                                },
                                {
                                    "variable": "referencedTable",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 540,
                                    "char": 70
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 540,
                                    "char": 79
                                },
                                {
                                    "variable": "referencedColumns",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 541,
                                    "char": 30
                                },
                                {
                                    "variable": "referenceUpdate",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 541,
                                    "char": 47
                                },
                                {
                                    "variable": "referenceDelete",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 541,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 543,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 543,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 543,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 545,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 545,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 545,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "dialect",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 545,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 545,
                                                "char": 55
                                            },
                                            "name": "describeReferences",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 545,
                                                        "char": 80
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 545,
                                                    "char": 80
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "schema",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 545,
                                                        "char": 88
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 545,
                                                    "char": 88
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 545,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 545,
                                        "char": 89
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Db",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 545,
                                                "char": 104
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "FETCH_NUM",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 545,
                                                "char": 104
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 545,
                                            "char": 104
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 545,
                                        "char": 104
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 545,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 546,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 546,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 546,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 546,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 548,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 548,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "constraintName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 548,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 548,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 548,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 548,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 549,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "3",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 549,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 549,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 549,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 550,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 550,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "4",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 550,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 550,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 550,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 551,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referenceUpdate",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "reference",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 551,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "6",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 551,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 551,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 551,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 552,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referenceDelete",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "reference",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 552,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "7",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 552,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 552,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 552,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 553,
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
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 553,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 553,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 554,
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
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 554,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 554,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 555,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 556,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 556,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 556,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedSchema",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 556,
                                                            "char": 84
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 556,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 556,
                                                    "char": 85
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 557,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 557,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 557,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 557,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 557,
                                                            "char": 83
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 557,
                                                        "char": 84
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 557,
                                                    "char": 84
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 558,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 558,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 558,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 558,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 558,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 558,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 558,
                                                    "char": 76
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 559,
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
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 559,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 559,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 559,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 559,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 559,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 559,
                                                    "char": 86
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 560,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referenceUpdate",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "references",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 560,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 560,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 560,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "onUpdate",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 560,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 560,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 560,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 561,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "referenceDelete",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "references",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 561,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "constraintName",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 561,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 561,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "onDelete",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 561,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 561,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 561,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 562,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 564,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 564,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 564,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 564,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 564,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 565,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "5",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 565,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 565,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 565,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 567,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 567,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 568,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedSchema",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 568,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 568,
                                                        "char": 53
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 569,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedTable",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 569,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 569,
                                                        "char": 52
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 570,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "columns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 570,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 570,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 571,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referencedColumns",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 571,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 571,
                                                        "char": 54
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "onUpdate",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 572,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referenceUpdate",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 572,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 572,
                                                        "char": 52
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "onDelete",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 573,
                                                            "char": 35
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "referenceDelete",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 574,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 574,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 574,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 574,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 575,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 577,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 577,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 577,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 579,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "references",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 579,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 580,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 581,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 581,
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
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 583,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 583,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedSchema",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 583,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 583,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 583,
                                                                    "char": 73
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "referencedTable",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 584,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 584,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedTable",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 584,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 584,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 584,
                                                                    "char": 72
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "columns",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 585,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 585,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "columns",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 585,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 585,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 585,
                                                                    "char": 64
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "referencedColumns",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 586,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 586,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "referencedColumns",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 586,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 586,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 586,
                                                                    "char": 74
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "onUpdate",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 587,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 587,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "onUpdate",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 587,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 587,
                                                                        "char": 65
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 587,
                                                                    "char": 65
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "onDelete",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 588,
                                                                        "char": 39
                                                                    },
                                                                    "value": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "arrayReference",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 588,
                                                                            "char": 55
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "onDelete",
                                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                            "line": 588,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 589,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 589,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 590,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 590,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 590,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 590,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 591,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 593,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "referenceObjects",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 593,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 594,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 538,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 538,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 538,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 537,
                    "last-line": 615,
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
                                            "value": "DEFAULT",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 618,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 618,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 618,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 619,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 617,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 617,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 617,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 616,
                    "last-line": 623,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 624,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "schemaName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 624,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 624,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 624,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 624,
                                "char": 129
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 624,
                                "char": 137
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 624,
                            "char": 137
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 626,
                                    "char": 16
                                },
                                {
                                    "variable": "queries",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 626,
                                    "char": 25
                                },
                                {
                                    "variable": "query",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 626,
                                    "char": 32
                                },
                                {
                                    "variable": "exception",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 626,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 628,
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
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 628,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "dialect",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 628,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 628,
                                            "char": 33
                                        },
                                        "name": "modifyColumn",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tableName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 629,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 629,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 630,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 630,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 631,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 631,
                                                "char": 19
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "currentColumn",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 633,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 633,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 633,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 633,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 635,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "queries",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ";",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 635,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 635,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sql",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 635,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 635,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 635,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 635,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 637,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "queries",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 637,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 637,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 637,
                                    "char": 27
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 637,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 637,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "try-catch",
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 639,
                                                    "char": 22
                                                },
                                                "name": "begin",
                                                "call-type": 3,
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 639,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 641,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "queries",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 641,
                                                "char": 38
                                            },
                                            "value": "query",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "empty",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "query",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 642,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 642,
                                                        "char": 36
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 644,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 646,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 646,
                                                            "char": 26
                                                        },
                                                        "name": "query",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "query",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 646,
                                                                        "char": 41
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": ";",
                                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                        "line": 646,
                                                                        "char": 44
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                    "line": 646,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 646,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 646,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 647,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 649,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 649,
                                                    "char": 29
                                                },
                                                "name": "commit",
                                                "call-type": 3,
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 649,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 650,
                                            "char": 13
                                        }
                                    ],
                                    "catches": [
                                        {
                                            "classes": [
                                                {
                                                    "type": "variable",
                                                    "value": "Throwable",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 650,
                                                    "char": 30
                                                }
                                            ],
                                            "variable": {
                                                "type": "variable",
                                                "value": "exception",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 655,
                                                "char": 9
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 651,
                                                            "char": 22
                                                        },
                                                        "name": "rollback",
                                                        "call-type": 3,
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 651,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 653,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "throw",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "exception",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 653,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 654,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 655,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 655,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "sql",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 656,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 656,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 656,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                "line": 656,
                                                "char": 38
                                            },
                                            "name": "execute",
                                            "call-type": 3,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "queries",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 656,
                                                                "char": 56
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                                "line": 656,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 656,
                                                            "char": 60
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ";",
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                            "line": 656,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                        "line": 656,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                                    "line": 656,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 656,
                                            "char": 65
                                        },
                                        "extra": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                            "line": 656,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                        "line": 656,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                    "line": 657,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 659,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 659,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 660,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 625,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 625,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 624,
                    "last-line": 665,
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
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 668,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 669,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 667,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 667,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 666,
                    "last-line": 674,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 677,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 678,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 676,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 676,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 675,
                    "last-line": 682,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 685,
                                "char": 18
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                            "line": 686,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                                "line": 684,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                        "line": 684,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
                    "line": 683,
                    "last-line": 687,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
            "line": 40,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Adapter\/Pdo\/Postgresql.zep",
        "line": 40,
        "char": 5
    }
]