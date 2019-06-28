[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Db\\Reference\n *",
        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ReferenceInterface",
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
                            "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                            "line": 21,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Restore a Phalcon\\Db\\Reference object from export\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ReferenceInterface",
                                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                    "line": 21,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 21,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 21,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 21,
                    "last-line": 25,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumns",
                    "docblock": "**\n     * Gets local columns which reference is based\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 26,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 26,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "docblock": "**\n     * Gets the index name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 31,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 31,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOnDelete",
                    "docblock": "**\n     * Gets the referenced on delete\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 36,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 36,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOnUpdate",
                    "docblock": "**\n     * Gets the referenced on update\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 41,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 41,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReferencedColumns",
                    "docblock": "**\n     * Gets referenced columns\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 46,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 46,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReferencedSchema",
                    "docblock": "**\n     * Gets the schema where referenced table is\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 51,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 51,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReferencedTable",
                    "docblock": "**\n     * Gets the referenced table\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 56,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 56,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSchemaName",
                    "docblock": "**\n     * Gets the schema where referenced table is\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                                "line": 61,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                        "line": 61,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
                    "line": 61,
                    "last-line": 62,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
            "line": 62,
            "char": 1
        },
        "file": "\/app\/phalcon\/Db\/ReferenceInterface.zep",
        "line": 0,
        "char": 0
    }
]