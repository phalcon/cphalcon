[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Column.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/Column.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Exception",
                "file": "\/app\/phalcon\/Db\/Column.zep",
                "line": 13,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Db\/Column.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ColumnInterface",
                "file": "\/app\/phalcon\/Db\/Column.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Db\/Column.zep",
        "line": 38,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Allows to define columns to be used on create or alter table operations\n *\n *```php\n * use Phalcon\\Db\\Column as Column;\n *\n * \/\/ Column definition\n * $column = new Column(\n *     \"id\",\n *     [\n *         \"type\"          => Column::TYPE_INTEGER,\n *         \"size\"          => 10,\n *         \"unsigned\"      => true,\n *         \"notNull\"       => true,\n *         \"autoIncrement\" => true,\n *         \"first\"         => true,\n *     ]\n * );\n *\n * \/\/ Add column to existing table\n * $connection->addColumn(\"robots\", null, $column);\n *```\n *",
        "file": "\/app\/phalcon\/Db\/Column.zep",
        "line": 39,
        "char": 5
    },
    {
        "type": "class",
        "name": "Column",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ColumnInterface",
                "file": "\/app\/phalcon\/Db\/Column.zep",
                "line": 40,
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
                    "name": "after",
                    "docblock": "**\n     * Column Position\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 222,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "autoIncrement",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 223,
                        "char": 36
                    },
                    "docblock": "**\n     * Column is autoIncrement?\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 227,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "bindType",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 228,
                        "char": 27
                    },
                    "docblock": "**\n     * Bind Type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 232,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "_default",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 233,
                        "char": 31
                    },
                    "docblock": "**\n     * Default column value\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 233,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 239,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "first",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 240,
                        "char": 28
                    },
                    "docblock": "**\n     * Position is first\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 244,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "isNumeric",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 245,
                        "char": 32
                    },
                    "docblock": "**\n     * The column have some numeric type?\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 251,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "docblock": "**\n     * Column's name\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 252,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 258,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "notNull",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 259,
                        "char": 30
                    },
                    "docblock": "**\n     * Column not nullable?\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 263,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "primary",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 264,
                        "char": 30
                    },
                    "docblock": "**\n     * Column is part of the primary key?\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 270,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "scale",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 271,
                        "char": 25
                    },
                    "docblock": "**\n     * Integer column number scale\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 271,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 277,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "size",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 278,
                        "char": 24
                    },
                    "docblock": "**\n     * Integer column size\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 278,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 284,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * Column data type\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 285,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 291,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "typeReference",
                    "default": {
                        "type": "int",
                        "value": "-1",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 292,
                        "char": 34
                    },
                    "docblock": "**\n     * Column data type reference\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 292,
                            "char": 40
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 298,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "typeValues",
                    "docblock": "**\n     * Column data type values\n     *\n     * @var array|string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 299,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 305,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "unsigned",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 306,
                        "char": 31
                    },
                    "docblock": "**\n     * Integer column unsigned?\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 310,
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
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 311,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 311,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 17
                                },
                                {
                                    "variable": "notNull",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 26
                                },
                                {
                                    "variable": "primary",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 35
                                },
                                {
                                    "variable": "size",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 41
                                },
                                {
                                    "variable": "scale",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 48
                                },
                                {
                                    "variable": "dunsigned",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 59
                                },
                                {
                                    "variable": "first",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 66
                                },
                                {
                                    "variable": "after",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 313,
                                    "char": 73
                                },
                                {
                                    "variable": "bindType",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 314,
                                    "char": 21
                                },
                                {
                                    "variable": "isNumeric",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 314,
                                    "char": 32
                                },
                                {
                                    "variable": "autoIncrement",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 314,
                                    "char": 47
                                },
                                {
                                    "variable": "defaultValue",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 314,
                                    "char": 61
                                },
                                {
                                    "variable": "typeReference",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 314,
                                    "char": 76
                                },
                                {
                                    "variable": "typeValues",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 315,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 317,
                            "char": 11
                        },
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
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 317,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 317,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 322,
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
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 322,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 322,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 322,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 322,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 322,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 322,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 322,
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
                                                    "value": "Column type is required",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 323,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 323,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 323,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 324,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 326,
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
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 326,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 326,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 328,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "typeReference",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 328,
                                    "char": 59
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 328,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "typeReference",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 328,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 328,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 328,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "typeReference",
                                            "expr": {
                                                "type": "variable",
                                                "value": "typeReference",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 329,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 329,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 330,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 332,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "typeValues",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 332,
                                    "char": 53
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 332,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "typeValues",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 332,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 332,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 332,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "typeValues",
                                            "expr": {
                                                "type": "variable",
                                                "value": "typeValues",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 333,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 333,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 334,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 339,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "notNull",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 339,
                                    "char": 47
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 339,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "notNull",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 339,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 339,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 339,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "notNull",
                                            "expr": {
                                                "type": "variable",
                                                "value": "notNull",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 340,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 340,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 341,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 346,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "primary",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 346,
                                    "char": 47
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 346,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "primary",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 346,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 346,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 346,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "primary",
                                            "expr": {
                                                "type": "variable",
                                                "value": "primary",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 347,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 347,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 348,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 350,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "size",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 350,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 350,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "size",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 350,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 350,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 350,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "size",
                                            "expr": {
                                                "type": "variable",
                                                "value": "size",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 351,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 351,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 352,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 357,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "scale",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 357,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 357,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "scale",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 357,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 357,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 357,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 358,
                                        "char": 25
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 360,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_INTEGER",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 360,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 360,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 361,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 361,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_FLOAT",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 361,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 361,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 362,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 362,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_DECIMAL",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 362,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 362,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 363,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 363,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_DOUBLE",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 363,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 363,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 364,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 364,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_BIGINTEGER",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 364,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 364,
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
                                                            "property": "scale",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "scale",
                                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                "line": 365,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 365,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 366,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 368,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 368,
                                            "char": 23
                                        },
                                        {
                                            "type": "default",
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
                                                                    "value": "Column type does not support scale parameter",
                                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                    "line": 371,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                "line": 371,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 371,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 372,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 372,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 373,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 378,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "defaultValue",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 378,
                                    "char": 52
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 378,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "default",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 378,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 378,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 378,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "_default",
                                            "expr": {
                                                "type": "variable",
                                                "value": "defaultValue",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 379,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 379,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 380,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 385,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "dunsigned",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 385,
                                    "char": 50
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 385,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "unsigned",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 385,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 385,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 385,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "unsigned",
                                            "expr": {
                                                "type": "variable",
                                                "value": "dunsigned",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 386,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 386,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 387,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 392,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "isNumeric",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 392,
                                    "char": 51
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 392,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "isNumeric",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 392,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 392,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 392,
                                "char": 51
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "isNumeric",
                                            "expr": {
                                                "type": "variable",
                                                "value": "isNumeric",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 393,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 393,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 394,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 399,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "autoIncrement",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 399,
                                    "char": 59
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 399,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "autoIncrement",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 399,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 399,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 399,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "autoIncrement",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 400,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 400,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "autoIncrement",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 401,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 401,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 402,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "switch",
                                            "expr": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 403,
                                                "char": 29
                                            },
                                            "clauses": [
                                                {
                                                    "type": "case",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "self",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 404,
                                                            "char": 47
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "TYPE_BIGINTEGER",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 404,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 404,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 405,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "case",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "self",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 405,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "TYPE_INTEGER",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 405,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 405,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 406,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "case",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "self",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 406,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "TYPE_MEDIUMINTEGER",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 406,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 406,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 407,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "case",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "self",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 407,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "TYPE_SMALLINTEGER",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 407,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 407,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 408,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "case",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "self",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 408,
                                                            "char": 48
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "TYPE_TINYINTEGER",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 408,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 408,
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
                                                                    "property": "autoIncrement",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                        "line": 409,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                    "line": 409,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 410,
                                                            "char": 29
                                                        },
                                                        {
                                                            "type": "break",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 412,
                                                            "char": 27
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 412,
                                                    "char": 27
                                                },
                                                {
                                                    "type": "default",
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
                                                                            "value": "Column type cannot be auto-increment",
                                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                            "line": 415,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                        "line": 415,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                "line": 415,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 416,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 416,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 417,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 418,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 423,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "first",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 423,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 423,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "first",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 423,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 423,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 423,
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
                                            "property": "first",
                                            "expr": {
                                                "type": "variable",
                                                "value": "first",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 424,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 424,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 425,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 430,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "after",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 430,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 430,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "after",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 430,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 430,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 430,
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
                                            "property": "after",
                                            "expr": {
                                                "type": "variable",
                                                "value": "after",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 431,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 431,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 432,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 437,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "bindType",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 437,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 437,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "bindType",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 437,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 437,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 437,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "bindType",
                                            "expr": {
                                                "type": "variable",
                                                "value": "bindType",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 438,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 438,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 439,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 440,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Db\\Column constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 312,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 311,
                    "last-line": 444,
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
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 445,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columnType",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 447,
                                    "char": 23
                                },
                                {
                                    "variable": "notNull",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 447,
                                    "char": 32
                                },
                                {
                                    "variable": "size",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 447,
                                    "char": 38
                                },
                                {
                                    "variable": "dunsigned",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 447,
                                    "char": 49
                                },
                                {
                                    "variable": "after",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 447,
                                    "char": 56
                                },
                                {
                                    "variable": "isNumeric",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 447,
                                    "char": 67
                                },
                                {
                                    "variable": "first",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 447,
                                    "char": 74
                                },
                                {
                                    "variable": "bindType",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 448,
                                    "char": 21
                                },
                                {
                                    "variable": "primary",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 448,
                                    "char": 30
                                },
                                {
                                    "variable": "columnName",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 448,
                                    "char": 42
                                },
                                {
                                    "variable": "scale",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 448,
                                    "char": 49
                                },
                                {
                                    "variable": "defaultValue",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 448,
                                    "char": 63
                                },
                                {
                                    "variable": "autoIncrement",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 448,
                                    "char": 78
                                },
                                {
                                    "variable": "columnTypeReference",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 449,
                                    "char": 32
                                },
                                {
                                    "variable": "columnTypeValues",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 449,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 450,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 450,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 452,
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
                                        "value": "columnName",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 452,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 452,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "columnName",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 452,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 452,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 452,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 452,
                                "char": 48
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
                                                    "value": "columnName",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 453,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 453,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 453,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 453,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 453,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 453,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 453,
                                        "char": 55
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
                                                            "value": "Column name is required",
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 454,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                                        "line": 454,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 454,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 455,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 456,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 458,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "definition",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 458,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 458,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 460,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "columnType",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 460,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 460,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 460,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 460,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 460,
                                "char": 42
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
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 461,
                                                    "char": 32
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnType",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 461,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 461,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 462,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 464,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "columnTypeReference",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 464,
                                    "char": 60
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 464,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "typeReference",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 464,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 464,
                                    "char": 60
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 464,
                                "char": 60
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
                                                    "value": "typeReference",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 465,
                                                    "char": 41
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnTypeReference",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 465,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 465,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 466,
                                    "char": 9
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
                                                    "value": "typeReference",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 467,
                                                    "char": 41
                                                }
                                            ],
                                            "expr": {
                                                "type": "int",
                                                "value": "-1",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 467,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 467,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 468,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 470,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "columnTypeValues",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 470,
                                    "char": 54
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 470,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "typeValues",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 470,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 470,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 470,
                                "char": 54
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
                                                    "value": "typeValues",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 471,
                                                    "char": 38
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnTypeValues",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 471,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 471,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 472,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 474,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "notNull",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 474,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 474,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "notNull",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 474,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 474,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 474,
                                "char": 41
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
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 475,
                                                    "char": 35
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "notNull",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 475,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 475,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 476,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 478,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "primary",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 478,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 478,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "primary",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 478,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 478,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 478,
                                "char": 41
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
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 479,
                                                    "char": 35
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "primary",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 479,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 479,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 480,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 482,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "size",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 482,
                                    "char": 35
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 482,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "size",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 482,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 482,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 482,
                                "char": 35
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
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 483,
                                                    "char": 32
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "size",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 483,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 483,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 484,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 486,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "scale",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 486,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 486,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "scale",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 486,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 486,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 486,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 488,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 488,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 488,
                                        "char": 37
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 490,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_INTEGER",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 490,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 490,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 491,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 491,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_FLOAT",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 491,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 491,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 492,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 492,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_DECIMAL",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 492,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 492,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 493,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 493,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_DOUBLE",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 493,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 493,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 494,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 494,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "TYPE_BIGINTEGER",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 494,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 494,
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
                                                                    "value": "scale",
                                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                    "line": 495,
                                                                    "char": 41
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "scale",
                                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                                "line": 495,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                                            "line": 495,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 496,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 497,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 497,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 498,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 500,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "defaultValue",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 500,
                                    "char": 46
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 500,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "default",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 500,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 500,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 500,
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
                                                    "value": "default",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 501,
                                                    "char": 35
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "defaultValue",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 501,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 501,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 502,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 504,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "dunsigned",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 504,
                                    "char": 44
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 504,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "unsigned",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 504,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 504,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 504,
                                "char": 44
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
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 505,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "dunsigned",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 505,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 505,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 506,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 508,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "autoIncrement",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 508,
                                    "char": 53
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 508,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "autoIncrement",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 508,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 508,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 508,
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
                                                    "value": "autoIncrement",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 509,
                                                    "char": 41
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "autoIncrement",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 509,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 509,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 510,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 512,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "isNumeric",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 512,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 512,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "isNumeric",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 512,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 512,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 512,
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
                                                    "value": "isNumeric",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 513,
                                                    "char": 37
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "isNumeric",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 513,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 513,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 514,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 516,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "first",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 516,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 516,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "first",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 516,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 516,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 516,
                                "char": 37
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
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 517,
                                                    "char": 33
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "first",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 517,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 517,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 518,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 520,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "after",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 520,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 520,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "after",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 520,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 520,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 520,
                                "char": 37
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
                                                    "value": "after",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 521,
                                                    "char": 33
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "after",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 521,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 521,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 522,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 524,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "bindType",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 524,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 524,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "bindType",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 524,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 524,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 524,
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
                                                    "value": "bindType",
                                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                                    "line": 525,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "bindType",
                                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                                "line": 525,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 525,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 526,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 528,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "self",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "columnName",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 528,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 528,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Column.zep",
                                            "line": 528,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 528,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 528,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 529,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Restores the internal state of a Phalcon\\Db\\Column object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ColumnInterface",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 446,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 446,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 446,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 445,
                    "last-line": 533,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAfterPosition",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 536,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "after",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 536,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 536,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 537,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether field absolute to position in table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 535,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 535,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 534,
                    "last-line": 541,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBindType",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 544,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "bindType",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 544,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 544,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 545,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the type of bind handling\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 543,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 543,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 542,
                    "last-line": 549,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasDefault",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 552,
                                    "char": 17
                                },
                                "name": "isAutoIncrement",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 552,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 553,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 554,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 556,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 556,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "_default",
                                        "file": "\/app\/phalcon\/Db\/Column.zep",
                                        "line": 556,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 556,
                                    "char": 33
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 556,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 556,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 557,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether column has default value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 551,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 551,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 550,
                    "last-line": 561,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAutoIncrement",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 564,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "autoIncrement",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 564,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 564,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 565,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Auto-Increment\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 563,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 563,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 562,
                    "last-line": 569,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isFirst",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 572,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "first",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 572,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 572,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 573,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether column have first position in table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 571,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 571,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 570,
                    "last-line": 577,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isNotNull",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 580,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "notNull",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 580,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 580,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 581,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Not null\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 579,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 579,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 578,
                    "last-line": 585,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isNumeric",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 588,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "isNumeric",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 588,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 588,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 589,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether column have an numeric type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 587,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 587,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 586,
                    "last-line": 593,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isPrimary",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 596,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "primary",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 596,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 596,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 597,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Column is part of the primary key?\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 595,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 595,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 594,
                    "last-line": 601,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUnsigned",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 604,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "unsigned",
                                    "file": "\/app\/phalcon\/Db\/Column.zep",
                                    "line": 604,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 604,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Db\/Column.zep",
                            "line": 605,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns true if number column is unsigned\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Column.zep",
                                "line": 603,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 603,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 602,
                    "last-line": 606,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "BIND_PARAM_BLOB",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 44,
                        "char": 30
                    },
                    "docblock": "**\n     * Bind Type Blob\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 48,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "BIND_PARAM_BOOL",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 49,
                        "char": 30
                    },
                    "docblock": "**\n     * Bind Type Bool\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 53,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "BIND_PARAM_DECIMAL",
                    "default": {
                        "type": "int",
                        "value": "32",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 54,
                        "char": 34
                    },
                    "docblock": "**\n     * Bind Type Decimal\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 58,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "BIND_PARAM_INT",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 59,
                        "char": 29
                    },
                    "docblock": "**\n     * Bind Type Integer\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 63,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "BIND_PARAM_NULL",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 64,
                        "char": 30
                    },
                    "docblock": "**\n     * Bind Type Null\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 68,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "BIND_PARAM_STR",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 69,
                        "char": 29
                    },
                    "docblock": "**\n     * Bind Type String\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 73,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "BIND_SKIP",
                    "default": {
                        "type": "int",
                        "value": "1024",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 74,
                        "char": 27
                    },
                    "docblock": "**\n     * Skip binding by type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 78,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_BIGINTEGER",
                    "default": {
                        "type": "int",
                        "value": "14",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 79,
                        "char": 31
                    },
                    "docblock": "**\n     * Big integer abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 83,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_BIT",
                    "default": {
                        "type": "int",
                        "value": "19",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 84,
                        "char": 24
                    },
                    "docblock": "**\n     * Bit abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 88,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_BLOB",
                    "default": {
                        "type": "int",
                        "value": "11",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 89,
                        "char": 25
                    },
                    "docblock": "**\n     * Blob abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 93,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_BOOLEAN",
                    "default": {
                        "type": "int",
                        "value": "8",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 94,
                        "char": 27
                    },
                    "docblock": "**\n     * Bool abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 98,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_CHAR",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 99,
                        "char": 24
                    },
                    "docblock": "**\n     * Char abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 103,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_DATE",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 104,
                        "char": 24
                    },
                    "docblock": "**\n     * Date abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 108,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_DATETIME",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 109,
                        "char": 28
                    },
                    "docblock": "**\n     * Datetime abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 113,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_DECIMAL",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 114,
                        "char": 27
                    },
                    "docblock": "**\n     * Decimal abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 118,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_DOUBLE",
                    "default": {
                        "type": "int",
                        "value": "9",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 119,
                        "char": 26
                    },
                    "docblock": "**\n     * Double abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 123,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_ENUM",
                    "default": {
                        "type": "int",
                        "value": "18",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 124,
                        "char": 25
                    },
                    "docblock": "**\n     * Enum abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 128,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_FLOAT",
                    "default": {
                        "type": "int",
                        "value": "7",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 129,
                        "char": 25
                    },
                    "docblock": "**\n     * Float abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 133,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_INTEGER",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 134,
                        "char": 27
                    },
                    "docblock": "**\n     * Int abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 138,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_JSON",
                    "default": {
                        "type": "int",
                        "value": "15",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 139,
                        "char": 25
                    },
                    "docblock": "**\n     * Json abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 143,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_JSONB",
                    "default": {
                        "type": "int",
                        "value": "16",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 144,
                        "char": 26
                    },
                    "docblock": "**\n     * Jsonb abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 148,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_LONGBLOB",
                    "default": {
                        "type": "int",
                        "value": "13",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 149,
                        "char": 29
                    },
                    "docblock": "**\n     * Longblob abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 153,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_LONGTEXT",
                    "default": {
                        "type": "int",
                        "value": "24",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 154,
                        "char": 29
                    },
                    "docblock": "**\n     * Longtext abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 158,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_MEDIUMBLOB",
                    "default": {
                        "type": "int",
                        "value": "12",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 159,
                        "char": 31
                    },
                    "docblock": "**\n     * Mediumblob abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 163,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_MEDIUMINTEGER",
                    "default": {
                        "type": "int",
                        "value": "21",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 164,
                        "char": 34
                    },
                    "docblock": "**\n     * Mediumintegerr abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 168,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_MEDIUMTEXT",
                    "default": {
                        "type": "int",
                        "value": "23",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 169,
                        "char": 31
                    },
                    "docblock": "**\n     * Mediumtext abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 173,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_SMALLINTEGER",
                    "default": {
                        "type": "int",
                        "value": "22",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 174,
                        "char": 33
                    },
                    "docblock": "**\n     * Smallint abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 178,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_TEXT",
                    "default": {
                        "type": "int",
                        "value": "6",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 179,
                        "char": 24
                    },
                    "docblock": "**\n     * Text abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 183,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_TIME",
                    "default": {
                        "type": "int",
                        "value": "20",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 184,
                        "char": 25
                    },
                    "docblock": "**\n     * Time abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 188,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_TIMESTAMP",
                    "default": {
                        "type": "int",
                        "value": "17",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 189,
                        "char": 30
                    },
                    "docblock": "**\n     * Timestamp abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 193,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_TINYBLOB",
                    "default": {
                        "type": "int",
                        "value": "10",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 194,
                        "char": 29
                    },
                    "docblock": "**\n     * Tinyblob abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 198,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_TINYINTEGER",
                    "default": {
                        "type": "int",
                        "value": "26",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 199,
                        "char": 32
                    },
                    "docblock": "**\n     * Tinyint abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 203,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_TINYTEXT",
                    "default": {
                        "type": "int",
                        "value": "25",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 204,
                        "char": 29
                    },
                    "docblock": "**\n     * Tinytext abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 208,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "TYPE_VARCHAR",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Db\/Column.zep",
                        "line": 209,
                        "char": 27
                    },
                    "docblock": "**\n     * Varchar abstract data type\n     *",
                    "file": "\/app\/phalcon\/Db\/Column.zep",
                    "line": 215,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Db\/Column.zep",
            "line": 39,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Column.zep",
        "line": 39,
        "char": 5
    }
]