[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Db\\Column\n *",
        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ColumnInterface",
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                            "line": 21,
                            "char": 51
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
                                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                    "line": 21,
                                    "char": 73
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 21,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 21,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 21,
                    "last-line": 25,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAfterPosition",
                    "docblock": "**\n     * Check whether field absolute to position in table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 26,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 26,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBindType",
                    "docblock": "**\n     * Returns the type of bind handling\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 31,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 31,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefault",
                    "docblock": "**\n     * Returns default value of column\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 36,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 36,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "docblock": "**\n     * Returns column name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 41,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 41,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getScale",
                    "docblock": "**\n     * Returns column scale\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 46,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 46,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSize",
                    "docblock": "**\n     * Returns column size\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 51,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 51,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "docblock": "**\n     * Returns column type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 56,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 56,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTypeReference",
                    "docblock": "**\n     * Returns column type reference\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 61,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 61,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTypeValues",
                    "docblock": "**\n     * Returns column type values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 66,
                                "char": 46
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 66,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 66,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 66,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasDefault",
                    "docblock": "**\n     * Check whether column has default value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 72,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 72,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 72,
                    "last-line": 76,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAutoIncrement",
                    "docblock": "**\n     * Auto-Increment\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 77,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 77,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 77,
                    "last-line": 81,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isFirst",
                    "docblock": "**\n     * Check whether column have first position in table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 82,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 82,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 82,
                    "last-line": 86,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isNotNull",
                    "docblock": "**\n     * Not null\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 87,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 87,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 87,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isNumeric",
                    "docblock": "**\n     * Check whether column have an numeric type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 92,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 92,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 92,
                    "last-line": 96,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isPrimary",
                    "docblock": "**\n     * Column is part of the primary key?\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 97,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 97,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 97,
                    "last-line": 101,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUnsigned",
                    "docblock": "**\n     * Returns true if number column is unsigned\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                                "line": 102,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                        "line": 102,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
                    "line": 102,
                    "last-line": 103,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
            "line": 103,
            "char": 1
        },
        "file": "\/app\/phalcon\/Db\/ColumnInterface.zep",
        "line": 0,
        "char": 0
    }
]